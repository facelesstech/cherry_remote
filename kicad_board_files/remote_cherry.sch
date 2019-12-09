EESchema Schematic File Version 4
LIBS:remote_cherry-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push SW1
U 1 1 5DB4587F
P 3850 3600
F 0 "SW1" H 3850 3885 50  0000 C CNN
F 1 "SW_Push" H 3850 3794 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX1A_1.00u_PCB" H 3850 3800 50  0001 C CNN
F 3 "" H 3850 3800 50  0001 C CNN
	1    3850 3600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5DBEF835
P 3850 4050
F 0 "SW2" H 3850 4335 50  0000 C CNN
F 1 "SW_Push" H 3850 4244 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX1A_1.00u_PCB" H 3850 4250 50  0001 C CNN
F 3 "" H 3850 4250 50  0001 C CNN
	1    3850 4050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5DBEF87E
P 3850 4450
F 0 "SW3" H 3850 4735 50  0000 C CNN
F 1 "SW_Push" H 3850 4644 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX1A_1.00u_PCB" H 3850 4650 50  0001 C CNN
F 3 "" H 3850 4650 50  0001 C CNN
	1    3850 4450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5DBEF8A8
P 3850 4850
F 0 "SW4" H 3850 5135 50  0000 C CNN
F 1 "SW_Push" H 3850 5044 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX1A_1.00u_PCB" H 3850 5050 50  0001 C CNN
F 3 "" H 3850 5050 50  0001 C CNN
	1    3850 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5DBEF92A
P 4250 2300
F 0 "D1" V 4195 2378 50  0000 L CNN
F 1 "LED" V 4286 2378 50  0000 L CNN
F 2 "LED_custom:through_hole_led" H 4250 2300 50  0001 C CNN
F 3 "~" H 4250 2300 50  0001 C CNN
	1    4250 2300
	0    1    1    0   
$EndComp
$Comp
L Transistor_BJT:2N2219 Q1
U 1 1 5DBEFDC6
P 4350 3150
F 0 "Q1" H 4541 3104 50  0000 L CNN
F 1 "2N2219" H 4541 3195 50  0000 L CNN
F 2 "transistor_custom:2n2222" H 4550 3075 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/2N2219-D.PDF" H 4350 3150 50  0001 L CNN
	1    4350 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 2950 4250 2800
Wire Wire Line
	4250 3350 4250 3900
Wire Wire Line
	4250 3900 5800 3900
Wire Wire Line
	4800 2850 4900 2850
Wire Wire Line
	4800 4050 4050 4050
Wire Wire Line
	4750 4450 4050 4450
Wire Wire Line
	4700 4850 4050 4850
Wire Wire Line
	3650 4850 3500 4850
Wire Wire Line
	3500 4850 3500 4450
Wire Wire Line
	3500 2850 4800 2850
Connection ~ 4800 2850
Wire Wire Line
	3650 3600 3500 3600
Connection ~ 3500 3600
Wire Wire Line
	3500 3600 3500 2850
Wire Wire Line
	3650 4050 3500 4050
Connection ~ 3500 4050
Wire Wire Line
	3500 4050 3500 3600
Wire Wire Line
	3650 4450 3500 4450
Connection ~ 3500 4450
Wire Wire Line
	3500 4450 3500 4050
$Comp
L Device:R R1
U 1 1 5DC07E3A
P 4250 2650
F 0 "R1" H 4320 2696 50  0000 L CNN
F 1 "R" H 4320 2605 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4180 2650 50  0001 C CNN
F 3 "~" H 4250 2650 50  0001 C CNN
	1    4250 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2450 4250 2500
Wire Wire Line
	4800 2150 4800 2850
$Comp
L USB_C_lipo_charger_custom:USB_C_lipo_charger_custom U2
U 1 1 5DC08C03
P 7100 3900
F 0 "U2" H 7328 4396 50  0000 L CNN
F 1 "USB_C_lipo_charger_custom" H 7328 4305 50  0000 L CNN
F 2 "power_bank_boards:USB_C_SMD_lipo_charger_custom" H 7100 3900 50  0001 C CNN
F 3 "" H 7100 3900 50  0001 C CNN
	1    7100 3900
	1    0    0    -1  
$EndComp
$Comp
L arduino_pro_mini:arduino_pro_mini U1
U 1 1 5DC33FFA
P 5050 3100
F 0 "U1" V 4368 2850 50  0000 C CNN
F 1 "arduino_pro_mini" V 4277 2850 50  0000 C CNN
F 2 "arduino:arduino_pro_mini_SMD" H 5050 3100 50  0001 C CNN
F 3 "" H 5050 3100 50  0001 C CNN
	1    5050 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5700 2850 5800 2850
Wire Wire Line
	5800 2850 5800 3750
Wire Wire Line
	4900 3050 4550 3050
Wire Wire Line
	4550 3050 4550 3150
Wire Wire Line
	4900 3150 4850 3150
Wire Wire Line
	4850 3150 4850 3600
Wire Wire Line
	4900 3250 4800 3250
Wire Wire Line
	4800 3250 4800 4050
Wire Wire Line
	4900 3350 4750 3350
Wire Wire Line
	4750 3350 4750 4450
Wire Wire Line
	4900 3450 4700 3450
Wire Wire Line
	4050 3600 4700 3600
$Comp
L Switch:SW_Push SW5
U 1 1 5DC3622E
P 3850 5250
F 0 "SW5" H 3850 5535 50  0000 C CNN
F 1 "SW_Push" H 3850 5444 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX1A_1.00u_PCB" H 3850 5450 50  0001 C CNN
F 3 "" H 3850 5450 50  0001 C CNN
	1    3850 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3550 4650 3550
Wire Wire Line
	4650 3550 4650 5250
Wire Wire Line
	4650 5250 4050 5250
Wire Wire Line
	3500 4850 3500 5250
Wire Wire Line
	3500 5250 3650 5250
Connection ~ 3500 4850
$Comp
L ftdi_custom:ftdi_custom U3
U 1 1 5DC70EDD
P 5300 1900
F 0 "U3" H 5012 1685 50  0000 R CNN
F 1 "ftdi_custom" H 5012 1776 50  0000 R CNN
F 2 "custom_connectors:gx-12_5pin" H 5250 1900 50  0001 C CNN
F 3 "" H 5250 1900 50  0001 C CNN
	1    5300 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	5100 2000 5050 2000
Wire Wire Line
	5050 2000 5050 2200
Wire Wire Line
	5200 2000 5200 2050
Wire Wire Line
	5200 2050 5150 2050
Wire Wire Line
	5150 2050 5150 2200
Wire Wire Line
	5300 2000 5300 2100
Wire Wire Line
	5300 2100 5250 2100
Wire Wire Line
	5250 2100 5250 2200
Wire Wire Line
	5400 2000 5400 2200
Wire Wire Line
	5400 2200 5350 2200
Wire Wire Line
	5500 2000 5500 2200
Wire Wire Line
	5500 2200 5450 2200
Wire Wire Line
	4900 3650 4900 4050
Wire Wire Line
	5050 4450 5050 5500
Wire Wire Line
	5050 5500 3500 5500
Wire Wire Line
	3500 5500 3500 5250
Connection ~ 3500 5250
$Comp
L tiny_boost_custom:tiny_boost_custom U4
U 1 1 5DCAB050
P 7150 2250
F 0 "U4" V 7340 2122 50  0000 R CNN
F 1 "tiny_boost_custom" V 7249 2122 50  0000 R CNN
F 2 "power_bank_boards:Tiny_boost_orange" H 7150 2250 50  0001 C CNN
F 3 "" H 7150 2250 50  0001 C CNN
	1    7150 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7100 2350 7100 2450
$Comp
L battery_custom:battery_custom U5
U 1 1 5DCACBB5
P 7500 2650
F 0 "U5" V 7449 2928 50  0000 L CNN
F 1 "battery_custom" V 7540 2928 50  0000 L CNN
F 2 "battery_connector_custom:jst_2pin_right_angle" H 7500 2650 50  0001 C CNN
F 3 "" H 7500 2650 50  0001 C CNN
	1    7500 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	7000 2900 7000 2700
Wire Wire Line
	7000 2700 7400 2700
Wire Wire Line
	7400 2600 7150 2600
Wire Wire Line
	7150 2600 7150 2900
Wire Wire Line
	7200 2350 7200 2400
Wire Wire Line
	7200 2400 5800 2400
Wire Wire Line
	5800 2400 5800 2850
Connection ~ 5800 2850
Wire Wire Line
	7100 2450 5950 2450
Wire Wire Line
	5950 2450 5950 2150
Wire Wire Line
	4250 2150 4800 2150
Connection ~ 7100 2450
Connection ~ 4800 2150
Wire Wire Line
	4800 2150 5950 2150
Wire Wire Line
	4700 3600 4850 3600
$Comp
L ir_receiver:ir_receiver U6
U 1 1 5DD06F8F
P 5900 3650
F 0 "U6" V 5941 3123 50  0000 R CNN
F 1 "ir_receiver" V 5850 3123 50  0000 R CNN
F 2 "LED_custom:ir_receiver" H 5900 3650 50  0001 C CNN
F 3 "" H 5900 3650 50  0001 C CNN
	1    5900 3650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5700 3550 5900 3550
Wire Wire Line
	5900 3750 5800 3750
Connection ~ 5800 3750
Wire Wire Line
	5800 3750 5800 3900
Wire Wire Line
	5900 5500 5050 5500
Connection ~ 5050 5500
Wire Wire Line
	5900 3650 5900 5500
$Comp
L m3_standoffs:m3_standsoffs U7
U 1 1 5DD0C9C0
P 9050 1750
F 0 "U7" H 9108 1785 50  0000 L CNN
F 1 "m3_standsoffs" H 9108 1694 50  0000 L CNN
F 2 "m3_hole_custom:m3_hole_custom" H 9050 1750 50  0001 C CNN
F 3 "" H 9050 1750 50  0001 C CNN
	1    9050 1750
	1    0    0    -1  
$EndComp
$Comp
L m3_standoffs:m3_standsoffs U8
U 1 1 5DD0CA9D
P 9050 1950
F 0 "U8" H 9108 1985 50  0000 L CNN
F 1 "m3_standsoffs" H 9108 1894 50  0000 L CNN
F 2 "m3_hole_custom:m3_hole_custom" H 9050 1950 50  0001 C CNN
F 3 "" H 9050 1950 50  0001 C CNN
	1    9050 1950
	1    0    0    -1  
$EndComp
$Comp
L m3_standoffs:m3_standsoffs U9
U 1 1 5DD0CADD
P 9050 2150
F 0 "U9" H 9108 2185 50  0000 L CNN
F 1 "m3_standsoffs" H 9108 2094 50  0000 L CNN
F 2 "m3_hole_custom:m3_hole_custom" H 9050 2150 50  0001 C CNN
F 3 "" H 9050 2150 50  0001 C CNN
	1    9050 2150
	1    0    0    -1  
$EndComp
$Comp
L m3_standoffs:m3_standsoffs U10
U 1 1 5DD0CB17
P 9050 2350
F 0 "U10" H 9108 2385 50  0000 L CNN
F 1 "m3_standsoffs" H 9108 2294 50  0000 L CNN
F 2 "m3_hole_custom:m3_hole_custom" H 9050 2350 50  0001 C CNN
F 3 "" H 9050 2350 50  0001 C CNN
	1    9050 2350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SP3T SW6
U 1 1 5DD0E5C6
P 7800 3250
F 0 "SW6" H 7800 2925 50  0000 C CNN
F 1 "SW_SP3T" H 7800 3016 50  0000 C CNN
F 2 "buttons_custom:3_way_switch" H 7175 3425 50  0001 C CNN
F 3 "" H 7175 3425 50  0001 C CNN
	1    7800 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	7000 2350 7000 2500
Wire Wire Line
	7000 2500 6900 2500
Wire Wire Line
	6900 2500 6900 2900
Wire Wire Line
	7250 2900 7550 2900
Wire Wire Line
	7100 2450 8000 2450
Wire Wire Line
	4900 4050 7450 4050
Wire Wire Line
	8000 2450 8000 3250
Wire Wire Line
	7450 3150 7600 3150
Wire Wire Line
	7450 3150 7450 4050
Wire Wire Line
	7600 3350 7550 3350
Wire Wire Line
	7550 3350 7550 2900
Wire Wire Line
	4700 3450 4700 4850
$EndSCHEMATC
