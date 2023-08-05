#include <Arduino.h>
// Button input stuff
const int button0 = 4; // Button set to pin 4 
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
const int button2 = 6; // Button set to pin 6
long time_button2 = 0; // the last time the output pin was toggled
long debounce2 = 50; // the debounce time, increase if the output flickers
int reading_button2; // the current reading from the input pin
int previous_button2 = HIGH; // the previous reading from the input pin

// Button screen off stuff
const int button3 = 7; // Button set to pin 7 
long time_button3 = 0; // the last time the output pin was toggled
long debounce3 = 50; // the debounce time, increase if the output flickers
int reading_button3; // the current reading from the input pin
int previous_button3 = HIGH; // the previous reading from the input pin

// Button screen off stuff
const int button4 = 8; // Button set to pin 8 
long time_button4 = 0; // the last time the output pin was toggled
long debounce4 = 50; // the debounce time, increase if the output flickers
int reading_button4; // the current reading from the input pin
int previous_button4 = HIGH; // the previous reading from the input pin

const int buttonPin1 = 9; // the number of the pushbutton pin
int buttonState1 = 0; // variable for reading the pushbutton status
boolean buttonOne = 0;

/// recieve_stuff ///
/*
 * Specify which protocol(s) should be used for decoding.
 * If no protocol is defined, all protocols (except Bang&Olufsen) are active.
 * This must be done before the #include <IRremote.hpp>
 */
#define DECODE_DENON        // Includes Sharp
#define DECODE_JVC
#define DECODE_KASEIKYO
#define DECODE_PANASONIC    // alias for DECODE_KASEIKYO
#define DECODE_LG
#define DECODE_NEC          // Includes Apple and Onkyo
#define DECODE_SAMSUNG
#define DECODE_SONY
#define DECODE_RC5
#define DECODE_RC6

#define DECODE_BOSEWAVE
#define DECODE_LEGO_PF
#define DECODE_MAGIQUEST
#define DECODE_WHYNTER
#define DECODE_FAST

//#define DECODE_DISTANCE_WIDTH // Universal decoder for pulse distance width proto    cols
//#define DECODE_HASH         // special decoder for all protocols

//#define DECODE_BEO          // This protocol must always be enabled manually, i.e    . it is NOT enabled if no protocol is defined. It prevents decoding of SONY!

//#define DEBUG               // Activate this for lots of lovely debug output from     the decoders.

//#define RAW_BUFFER_LENGTH  180  // Default is 112 if DECODE_MAGIQUEST is enabled,     otherwise 100.

/// recieve_stuff ///


//#define DISABLE_CODE_FOR_RECEIVER // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.


//#define SEND_PWM_BY_TIMER         // Disable carrier PWM generation in software and use (restricted) hardware PWM.
//#define USE_NO_SEND_PWM           // Use no carrier PWM, just simulate an active low receiver signal. Overrides SEND_PWM_BY_TIMER definition

#include "PinDefinitionsAndMore.h" // Define macros for input and output pin etc.
#include <IRremote.hpp>

void setup() {
  Serial.begin(115200);
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

  pinMode(buttonPin1, INPUT);     
  digitalWrite(buttonPin1, HIGH); // initiate the internal pull up resistor
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW) 
  {
    Serial.println("button 1 pressed") ;
    buttonOne = 1;
    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
    Serial.println(F("at pin " STR(IR_RECEIVE_PIN)));
  }

    pinMode(LED_BUILTIN, OUTPUT);

    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
    Serial.print(F("Send IR signals at pin "));
    Serial.println(IR_SEND_PIN);

    IrSender.begin(DISABLE_LED_FEEDBACK); 
// Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin f    rom the internal boards definition as default feedback LED
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  }

//uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void loop() {

 // ------------- Debound code button input start code -------------
  reading_button0 = digitalRead(button0);

  if (reading_button0 == HIGH && previous_button0 == LOW && millis() - time_button0 > debounce0) { 
    time_button0 = millis(); 
    Serial.println("button press on/off");
    IrSender.sendSamsung(0x707, 0x2, 0);
  }
  previous_button0 = reading_button0;
   
 // -------------- Debound code button input end code -------------

 // ------------- Debound code button vol up start code -------------
  reading_button1 = digitalRead(button1);

  if (reading_button1 == HIGH && previous_button1 == LOW && millis() - time_button1 > debounce1) { 
    time_button1 = millis(); 
//    IrSender.sendSamsung(0x707, 0xB, sRepeats);
    IrSender.sendSamsung(0x707, 0x1, 0);

    Serial.println("button press Source");
  }
  previous_button1 = reading_button1;
   
 // -------------- Debound code button vol up end code -------------

 // ------------- Debound code button vol down start code -------------
  reading_button2 = digitalRead(button2);

  if (reading_button2 == HIGH && previous_button2 == LOW && millis() - time_button1 > debounce2) { 
    time_button2 = millis(); 
    IrSender.sendSamsung(0x707, 0x7, sRepeats);
    Serial.println("button press vol up");
  }
  previous_button2 = reading_button2;
   
 // -------------- Debound code button vol down end code -------------

 // ------------- Debound code button Screen off start code -------------
  reading_button3 = digitalRead(button3);

  if (reading_button3 == HIGH && previous_button3 == LOW && millis() - time_button3 > debounce3) { 
    time_button3 = millis(); 
    Serial.println("button press screen off");
  }
  previous_button3 = reading_button3;
   
 // -------------- Debound code button Screen off end code -------------

 // ------------- Debound code button tv off/on start code -------------
  reading_button4 = digitalRead(button4);

  if (reading_button4 == HIGH && previous_button4 == LOW && millis() - time_button4 > debounce4) { 
    time_button4 = millis(); 
    Serial.println("button press vol down");
    IrSender.sendSamsung(0x707, 0xB, sRepeats);
  }
  previous_button4 = reading_button4;
   
 // -------------- Debound code button tv off/on end code -------------
  
if (buttonOne == 1)
    {

    if (IrReceiver.decode()) {

        /*
         * Print a short summary of received data
         */
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.printIRSendUsage(&Serial);
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
            // We have an unknown protocol here, print more info
            IrReceiver.printIRResultRawFormatted(&Serial, true);
        }
        Serial.println();

        /*
         * !!!Important!!! Enable receiving of the next value,
         * since receiving has stopped after the end of the current received data packet.
         */
        IrReceiver.resume(); // Enable receiving of the next value

        /*
         * Finally, check the received data and perform actions according to the received command
         */
        if (IrReceiver.decodedIRData.command == 0x10) {
            // do something
        } else if (IrReceiver.decodedIRData.command == 0x11) {
            // do something else
        }
    }
  }
}

