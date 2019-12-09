// Button input stuff
const int button0 = 4; // Button set to pin 5
long time_button0 = 0; // the last time the output pin was toggled
long debounce0 = 50; // the debounce time, increase if the output flickers
int reading_button0; // the current reading from the input pin
int previous_button0 = HIGH; // the previous reading from the input pin

// Button vol up stuff
const int button1 = 5; // Button set to pin 5
long time_button1 = 0; // the last time the output pin was toggled
long debounce1 = 50; // the debounce time, increase if the output flickers
int reading_button1; // the current reading from the input pin
int previous_button1 = HIGH; // the previous reading from the input pin

// Button vol up stuff
const int button2 = 6; // Button set to pin 5
long time_button2 = 0; // the last time the output pin was toggled
long debounce2 = 50; // the debounce time, increase if the output flickers
int reading_button2; // the current reading from the input pin
int previous_button2 = HIGH; // the previous reading from the input pin

// Button screen off stuff
const int button3 = 7; // Button set to pin 5
long time_button3 = 0; // the last time the output pin was toggled
long debounce3 = 50; // the debounce time, increase if the output flickers
int reading_button3; // the current reading from the input pin
int previous_button3 = HIGH; // the previous reading from the input pin

// Button screen off stuff
const int button4 = 8; // Button set to pin 5
long time_button4 = 0; // the last time the output pin was toggled
long debounce4 = 50; // the debounce time, increase if the output flickers
int reading_button4; // the current reading from the input pin
int previous_button4 = HIGH; // the previous reading from the input pin

//------------------------------------------------------------------------------
// Include the IRremote library header
//
#include <IRremote.h>

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 11;
IRrecv irrecv(recvPin);

const int buttonPin1 = 9; // the number of the pushbutton pin
int buttonState1 = 0; // variable for reading the pushbutton status
boolean buttonOne = 0;

#include <IRremote.h>
IRsend irsend;

void setup() {
  pinMode(button0, INPUT); // Set the button as input
  digitalWrite(button0, HIGH); // initiate the internal pull up resistor
  pinMode(button1, INPUT); // Set the button as input
  digitalWrite(button1, HIGH); // initiate the internal pull up resistor
  pinMode(button2, INPUT); // Set the button as input
  digitalWrite(button2, HIGH); // initiate the internal pull up resistor
  pinMode(button3, INPUT); // Set the button as input
  digitalWrite(button3, HIGH); // initiate the internal pull up resistor
  pinMode(button4, INPUT); // Set the button as input
  digitalWrite(button4, HIGH); // initiate the internal pull up resistor
  Serial.begin(9600);

  pinMode(buttonPin1, INPUT);     
  digitalWrite(buttonPin1, HIGH); // initiate the internal pull up resistor
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW) 
  {
   Serial.println("button 1 pressed") ;
   buttonOne = 1;
  }
  irrecv.enableIRIn();  // Start the receiver

  }


void  ircode (decode_results *results)
{
  // Panasonic has an Address
  if (results->decode_type == PANASONIC) {
    Serial.print(results->address, HEX);
    Serial.print(":");
  }

  // Print Code
  Serial.print(results->value, HEX);
}

//+=============================================================================
// Display encoding type
//
void  encoding (decode_results *results)
{
  switch (results->decode_type) {
    default:
    case UNKNOWN:      Serial.print("UNKNOWN");       break ;
    case NEC:          Serial.print("NEC");           break ;
    case SONY:         Serial.print("SONY");          break ;
    case RC5:          Serial.print("RC5");           break ;
    case RC6:          Serial.print("RC6");           break ;
    case DISH:         Serial.print("DISH");          break ;
    case SHARP:        Serial.print("SHARP");         break ;
    case JVC:          Serial.print("JVC");           break ;
    case SANYO:        Serial.print("SANYO");         break ;
    case MITSUBISHI:   Serial.print("MITSUBISHI");    break ;
    case SAMSUNG:      Serial.print("SAMSUNG");       break ;
    case LG:           Serial.print("LG");            break ;
    case WHYNTER:      Serial.print("WHYNTER");       break ;
    case AIWA_RC_T501: Serial.print("AIWA_RC_T501");  break ;
    case PANASONIC:    Serial.print("PANASONIC");     break ;
    case DENON:        Serial.print("Denon");         break ;
  }
}

//+=============================================================================
// Dump out the decode_results structure.
//
void  dumpInfo (decode_results *results)
{
  // Check if the buffer overflowed
  if (results->overflow) {
    Serial.println("IR code too long. Edit IRremoteInt.h and increase RAWBUF");
    return;
  }

  // Show Encoding standard
  Serial.print("Encoding  : ");
  encoding(results);
  Serial.println("");

  // Show Code & length
  Serial.print("Code      : ");
  ircode(results);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
}

//+=============================================================================
// Dump out the decode_results structure.
//
void  dumpRaw (decode_results *results)
{
  // Print Raw data
  Serial.print("Timing[");
  Serial.print(results->rawlen-1, DEC);
  Serial.println("]: ");

  for (int i = 1;  i < results->rawlen;  i++) {
    unsigned long  x = results->rawbuf[i] * USECPERTICK;
    if (!(i & 1)) {  // even
      Serial.print("-");
      if (x < 1000)  Serial.print(" ") ;
      if (x < 100)   Serial.print(" ") ;
      Serial.print(x, DEC);
    } else {  // odd
      Serial.print("     ");
      Serial.print("+");
      if (x < 1000)  Serial.print(" ") ;
      if (x < 100)   Serial.print(" ") ;
      Serial.print(x, DEC);
      if (i < results->rawlen-1) Serial.print(", "); //',' not needed for last one
    }
    if (!(i % 8))  Serial.println("");
  }
  Serial.println("");                    // Newline
}

//+=============================================================================
// Dump out the decode_results structure.
//
void  dumpCode (decode_results *results)
{
  // Start declaration
  Serial.print("unsigned int  ");          // variable type
  Serial.print("rawData[");                // array name
  Serial.print(results->rawlen - 1, DEC);  // array size
  Serial.print("] = {");                   // Start declaration

  // Dump data
  for (int i = 1;  i < results->rawlen;  i++) {
    Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
    if ( i < results->rawlen-1 ) Serial.print(","); // ',' not needed on last one
    if (!(i & 1))  Serial.print(" ");
  }

  // End declaration
  Serial.print("};");  // 

  // Comment
  Serial.print("  // ");
  encoding(results);
  Serial.print(" ");
  ircode(results);

  // Newline
  Serial.println("");

  // Now dump "known" codes
  if (results->decode_type != UNKNOWN) {

    // Some protocols have an address
    if (results->decode_type == PANASONIC) {
      Serial.print("unsigned int  addr = 0x");
      Serial.print(results->address, HEX);
      Serial.println(";");
    }

    // All protocols have data
    Serial.print("unsigned int  data = 0x");
    Serial.print(results->value, HEX);
    Serial.println(";");
  }
}

//+=============================================================================


void loop() {

  if (buttonOne == 1)
    {
//      theaterChaseRainbow(50);
//      Serial.println("buttonOne is 1");
//  }

 // ------------- Debound code button input start code -------------
  reading_button0 = digitalRead(button0);

  if (reading_button0 == HIGH && previous_button0 == LOW && millis() - time_button0 > debounce0) { 
    time_button0 = millis(); 
//    irsend.sendNEC(0xFE7887, 32); // Vol up
//    irsend.sendNEC(0xFEFA05, 32); // Vol down
//    irsend.sendNEC(0xFE18E7, 32); // Screen off
//    irsend.sendNEC(0xFE50AF, 32); // TV on/off
   // Do something here
    Serial.println("button press");
    irsend.sendNEC(0xFECA35, 32); // Input
  }
  previous_button0 = reading_button0;
   
 // -------------- Debound code button input end code -------------

 // ------------- Debound code button vol up start code -------------
  reading_button1 = digitalRead(button1);

  if (reading_button1 == HIGH && previous_button1 == LOW && millis() - time_button1 > debounce1) { 
    time_button1 = millis(); 
//    irsend.sendNEC(0xFEFA05, 32); // Vol down
//    irsend.sendNEC(0xFE18E7, 32); // Screen off
//    irsend.sendNEC(0xFE50AF, 32); // TV on/off
   // Do something here
    irsend.sendNEC(0xFE7887, 32); // Vol up
    Serial.println("button press");
  }
  previous_button1 = reading_button1;
   
 // -------------- Debound code button vol up end code -------------

 // ------------- Debound code button vol down start code -------------
  reading_button2 = digitalRead(button2);

  if (reading_button2 == HIGH && previous_button2 == LOW && millis() - time_button1 > debounce2) { 
    time_button2 = millis(); 
    irsend.sendNEC(0xFEFA05, 32); // Vol down
    Serial.println("button press");
  }
  previous_button2 = reading_button2;
   
 // -------------- Debound code button vol down end code -------------

 // ------------- Debound code button Screen off start code -------------
  reading_button3 = digitalRead(button3);

  if (reading_button3 == HIGH && previous_button3 == LOW && millis() - time_button3 > debounce3) { 
    time_button3 = millis(); 
    Serial.println("button press");
    irsend.sendNEC(0xFE18E7, 32); // Screen off
  }
  previous_button3 = reading_button3;
   
 // -------------- Debound code button Screen off end code -------------

 // ------------- Debound code button tv off/on start code -------------
  reading_button4 = digitalRead(button4);

  if (reading_button4 == HIGH && previous_button4 == LOW && millis() - time_button4 > debounce4) { 
    time_button4 = millis(); 
    Serial.println("button press");
    irsend.sendNEC(0xFE50AF, 32); // TV on/off
  }
  previous_button4 = reading_button4;
   
 // -------------- Debound code button tv off/on end code -------------
}
  
if (buttonOne == 0)
    {

//    Serial.println("reciecv part code");
// The repeating section of the code
//
  decode_results  results;        // Somewhere to store the results

  if (irrecv.decode(&results)) {  // Grab an IR code
    dumpInfo(&results);           // Output the results
    dumpRaw(&results);            // Output the results in RAW format
    dumpCode(&results);           // Output the results as source code
    Serial.println("");           // Blank line between entries
    irrecv.resume();              // Prepare for the next value
  }
  }

    

  
  
}

