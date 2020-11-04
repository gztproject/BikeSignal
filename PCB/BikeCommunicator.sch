EESchema Schematic File Version 4
EELAYER 30 0
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
L Switch:SW_SPST_LED SW1
U 1 1 5EDB7F38
P 7500 1750
F 0 "SW1" H 7500 2085 50  0000 C CNN
F 1 "SW_SPST_LED_Green" H 7500 1994 50  0000 C CNN
F 2 "Buttons_Switches_Keyboard:SW_Cherry_MX1A_LED_1.00u_PCB" H 7500 2050 50  0001 C CNN
F 3 "~" H 7500 2050 50  0001 C CNN
	1    7500 1750
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST_LED SW3
U 1 1 5EDB8519
P 9000 1750
F 0 "SW3" H 9000 2085 50  0000 C CNN
F 1 "SW_SPST_LED_Yellow" H 9000 1994 50  0000 C CNN
F 2 "Buttons_Switches_Keyboard:SW_Cherry_MX1A_LED_1.00u_PCB" H 9000 2050 50  0001 C CNN
F 3 "~" H 9000 2050 50  0001 C CNN
	1    9000 1750
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST_LED SW2
U 1 1 5EDB8962
P 7500 2750
F 0 "SW2" H 7500 3085 50  0000 C CNN
F 1 "SW_SPST_LED_Blue" H 7500 2994 50  0000 C CNN
F 2 "Buttons_Switches_Keyboard:SW_Cherry_MX1A_LED_1.00u_PCB" H 7500 3050 50  0001 C CNN
F 3 "~" H 7500 3050 50  0001 C CNN
	1    7500 2750
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST_LED SW4
U 1 1 5EDB8D9D
P 9000 2750
F 0 "SW4" H 9000 3085 50  0000 C CNN
F 1 "SW_SPST_LED_Red" H 9000 2994 50  0000 C CNN
F 2 "Buttons_Switches_Keyboard:SW_Cherry_MX1A_LED_1.00u_PCB" H 9000 3050 50  0001 C CNN
F 3 "~" H 9000 3050 50  0001 C CNN
	1    9000 2750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7700 1650 7700 1750
Wire Wire Line
	9200 1650 9200 1750
Wire Wire Line
	7700 2650 7700 2750
Connection ~ 7700 1750
Connection ~ 9200 1750
Wire Wire Line
	7700 2750 7700 3000
Connection ~ 7700 2750
NoConn ~ 2250 4200
NoConn ~ 2250 4350
NoConn ~ 2250 4500
NoConn ~ 2250 4900
NoConn ~ 2250 5050
NoConn ~ 4150 5650
NoConn ~ 4150 5800
$Comp
L power:GND #PWR05
U 1 1 5EDE2464
P 3200 6300
F 0 "#PWR05" H 3200 6050 50  0001 C CNN
F 1 "GND" H 3205 6127 50  0000 C CNN
F 2 "" H 3200 6300 50  0001 C CNN
F 3 "" H 3200 6300 50  0001 C CNN
	1    3200 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 6150 3200 6150
Wire Wire Line
	3350 6150 3200 6150
Connection ~ 3200 6150
Wire Wire Line
	3200 6300 3200 6150
Wire Wire Line
	9200 2750 9200 2650
Wire Wire Line
	9200 1750 9200 2650
Connection ~ 9200 2650
Wire Wire Line
	7700 1750 7700 2650
Connection ~ 7700 2650
$Comp
L Device:R R3
U 1 1 5EDF8745
P 7150 1350
F 0 "R3" H 7220 1396 50  0000 L CNN
F 1 "4k7" H 7220 1305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" V 7080 1350 50  0001 C CNN
F 3 "~" H 7150 1350 50  0001 C CNN
	1    7150 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5EDF9319
P 7150 2350
F 0 "R4" H 7220 2396 50  0000 L CNN
F 1 "4k7" H 7220 2305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" V 7080 2350 50  0001 C CNN
F 3 "~" H 7150 2350 50  0001 C CNN
	1    7150 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5EDF9682
P 8650 1350
F 0 "R7" H 8720 1396 50  0000 L CNN
F 1 "4k7" H 8720 1305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" V 8580 1350 50  0001 C CNN
F 3 "~" H 8650 1350 50  0001 C CNN
	1    8650 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5EDF99CF
P 8650 2350
F 0 "R8" H 8720 2396 50  0000 L CNN
F 1 "4k7" H 8720 2305 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" V 8580 2350 50  0001 C CNN
F 3 "~" H 8650 2350 50  0001 C CNN
	1    8650 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5EDFA247
P 7000 1750
F 0 "R1" V 6793 1750 50  0000 C CNN
F 1 "0R" V 6884 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 6930 1750 50  0001 C CNN
F 3 "~" H 7000 1750 50  0001 C CNN
	1    7000 1750
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5EDFA92A
P 7000 2750
F 0 "R2" V 6793 2750 50  0000 C CNN
F 1 "220R" V 6884 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 6930 2750 50  0001 C CNN
F 3 "~" H 7000 2750 50  0001 C CNN
	1    7000 2750
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5EDFAD2E
P 8500 1750
F 0 "R5" V 8293 1750 50  0000 C CNN
F 1 "120R" V 8384 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 8430 1750 50  0001 C CNN
F 3 "~" H 8500 1750 50  0001 C CNN
	1    8500 1750
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5EDFB058
P 8500 2750
F 0 "R6" V 8293 2750 50  0000 C CNN
F 1 "120R" V 8384 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 8430 2750 50  0001 C CNN
F 3 "~" H 8500 2750 50  0001 C CNN
	1    8500 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	8800 2750 8650 2750
Wire Wire Line
	8800 2650 8650 2650
Wire Wire Line
	8650 2650 8650 2500
Wire Wire Line
	8650 1500 8650 1650
Wire Wire Line
	8650 1650 8800 1650
Wire Wire Line
	8800 1750 8650 1750
Wire Wire Line
	7150 1500 7150 1650
Wire Wire Line
	7150 1650 7300 1650
Wire Wire Line
	7150 1750 7300 1750
Wire Wire Line
	7150 2500 7150 2650
Wire Wire Line
	7150 2650 7300 2650
Wire Wire Line
	7150 2750 7300 2750
$Comp
L hw-108:HW-108_DC-DC U1
U 1 1 5EE0EA32
P 2400 1100
F 0 "U1" H 2400 1615 50  0000 C CNN
F 1 "HW-108_DC-DC" H 2400 1524 50  0000 C CNN
F 2 "Modules:HW-108" H 2350 1000 50  0001 C CNN
F 3 "" H 2350 1000 50  0001 C CNN
	1    2400 1100
	1    0    0    -1  
$EndComp
NoConn ~ 1900 1350
$Comp
L power:GND #PWR04
U 1 1 5EE11451
P 2900 1000
F 0 "#PWR04" H 2900 750 50  0001 C CNN
F 1 "GND" H 2905 827 50  0000 C CNN
F 2 "" H 2900 1000 50  0001 C CNN
F 3 "" H 2900 1000 50  0001 C CNN
	1    2900 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5EE11AFF
P 1900 1000
F 0 "#PWR02" H 1900 750 50  0001 C CNN
F 1 "GND" H 1905 827 50  0000 C CNN
F 2 "" H 1900 1000 50  0001 C CNN
F 3 "" H 1900 1000 50  0001 C CNN
	1    1900 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR01
U 1 1 5EE11FE9
P 1900 900
F 0 "#PWR01" H 1900 750 50  0001 C CNN
F 1 "+12V" H 1915 1073 50  0000 C CNN
F 2 "" H 1900 900 50  0001 C CNN
F 3 "" H 1900 900 50  0001 C CNN
	1    1900 900 
	1    0    0    -1  
$EndComp
NoConn ~ 2950 3750
Entry Wire Line
	4450 5150 4550 5250
Entry Wire Line
	4450 5000 4550 5100
Entry Wire Line
	4450 4850 4550 4950
Entry Wire Line
	4450 4700 4550 4800
Entry Wire Line
	4450 4550 4550 4650
Entry Wire Line
	4450 4400 4550 4500
Entry Wire Line
	4450 4250 4550 4350
Entry Wire Line
	4450 4100 4550 4200
NoConn ~ 2250 5650
NoConn ~ 2250 5800
Wire Wire Line
	9200 2750 9200 3000
Wire Wire Line
	9200 3000 8500 3000
Connection ~ 9200 2750
$Comp
L power:GND #PWR09
U 1 1 5EE264AC
P 8500 3200
F 0 "#PWR09" H 8500 2950 50  0001 C CNN
F 1 "GND" H 8505 3027 50  0000 C CNN
F 2 "" H 8500 3200 50  0001 C CNN
F 3 "" H 8500 3200 50  0001 C CNN
	1    8500 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 3200 8500 3000
Connection ~ 8500 3000
Wire Wire Line
	8500 3000 7700 3000
Entry Wire Line
	6700 1550 6800 1650
Entry Wire Line
	6700 1650 6800 1750
Entry Wire Line
	6700 2550 6800 2650
Entry Wire Line
	6700 2650 6800 2750
Entry Wire Line
	8200 1550 8300 1650
Entry Wire Line
	8200 1650 8300 1750
Entry Wire Line
	8200 2550 8300 2650
Entry Wire Line
	8200 2650 8300 2750
Connection ~ 8650 1650
Connection ~ 8650 2650
Connection ~ 7150 2650
Connection ~ 7150 1650
$Comp
L power:+3.3V #PWR07
U 1 1 5EE3CA33
P 7150 1200
F 0 "#PWR07" H 7150 1050 50  0001 C CNN
F 1 "+3.3V" H 7165 1373 50  0000 C CNN
F 2 "" H 7150 1200 50  0001 C CNN
F 3 "" H 7150 1200 50  0001 C CNN
	1    7150 1200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR010
U 1 1 5EE3DF37
P 8650 1200
F 0 "#PWR010" H 8650 1050 50  0001 C CNN
F 1 "+3.3V" H 8665 1373 50  0000 C CNN
F 2 "" H 8650 1200 50  0001 C CNN
F 3 "" H 8650 1200 50  0001 C CNN
	1    8650 1200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR011
U 1 1 5EE3EC15
P 8650 2200
F 0 "#PWR011" H 8650 2050 50  0001 C CNN
F 1 "+3.3V" H 8665 2373 50  0000 C CNN
F 2 "" H 8650 2200 50  0001 C CNN
F 3 "" H 8650 2200 50  0001 C CNN
	1    8650 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR08
U 1 1 5EE3F1F1
P 7150 2200
F 0 "#PWR08" H 7150 2050 50  0001 C CNN
F 1 "+3.3V" H 7165 2373 50  0000 C CNN
F 2 "" H 7150 2200 50  0001 C CNN
F 3 "" H 7150 2200 50  0001 C CNN
	1    7150 2200
	1    0    0    -1  
$EndComp
Connection ~ 6700 800 
Wire Bus Line
	6650 800  6700 800 
Wire Bus Line
	6700 800  8200 800 
Wire Wire Line
	6800 1650 7150 1650
Wire Wire Line
	6800 1750 6850 1750
Wire Wire Line
	6800 2650 7150 2650
Wire Wire Line
	6850 2750 6800 2750
Wire Wire Line
	8300 2650 8650 2650
Wire Wire Line
	8350 2750 8300 2750
Wire Wire Line
	8300 1650 8650 1650
Wire Wire Line
	8350 1750 8300 1750
Text Label 6800 1650 0    50   ~ 0
BTN1
Text Label 6800 1750 0    50   ~ 0
LED1
Text Label 8300 1650 0    50   ~ 0
BTN3
Text Label 8300 1750 0    50   ~ 0
LED3
Text Label 6800 2650 0    50   ~ 0
BTN2
Text Label 6800 2750 0    50   ~ 0
LED2
Text Label 8300 2650 0    50   ~ 0
BTN4
Text Label 8300 2750 0    50   ~ 0
LED4
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5EE57A37
P 1750 900
F 0 "#FLG0101" H 1750 975 50  0001 C CNN
F 1 "PWR_FLAG" H 1750 1073 50  0000 C CNN
F 2 "" H 1750 900 50  0001 C CNN
F 3 "~" H 1750 900 50  0001 C CNN
	1    1750 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 900  1900 900 
Connection ~ 1900 900 
Wire Bus Line
	4550 800  6700 800 
Wire Wire Line
	4150 4100 4450 4100
Wire Wire Line
	4450 4250 4150 4250
Wire Wire Line
	4150 4400 4450 4400
Wire Wire Line
	4450 4550 4150 4550
Wire Wire Line
	4150 4700 4450 4700
Wire Wire Line
	4450 4850 4150 4850
Wire Wire Line
	4150 5000 4450 5000
Wire Wire Line
	4450 5150 4150 5150
Text Label 4200 4100 0    50   ~ 0
BTN1
Text Label 4200 4250 0    50   ~ 0
BTN2
Text Label 4200 4400 0    50   ~ 0
BTN3
Text Label 4200 4550 0    50   ~ 0
BTN4
Text Label 4200 4700 0    50   ~ 0
LED1
Text Label 4200 4850 0    50   ~ 0
LED2
Text Label 4200 5000 0    50   ~ 0
LED3
Text Label 4200 5150 0    50   ~ 0
LED4
$Comp
L MCU_Module:HTCC-AB01 U2
U 1 1 5EDD6327
P 3200 4950
F 0 "U2" H 3225 6556 50  0000 C CNN
F 1 "HTCC-AB01" H 3225 6465 50  0000 C CNN
F 2 "Modules:HTCC-AB01" H 2900 5350 50  0001 C CNN
F 3 "https://resource.heltec.cn/download/CubeCell/HTCC-AB01/HTCC-AB01_SchematicDiagram.pdf" H 2900 5350 50  0001 C CNN
	1    3200 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5EDD6E10
P 3400 3750
F 0 "#PWR0101" H 3400 3600 50  0001 C CNN
F 1 "+5V" H 3415 3923 50  0000 C CNN
F 2 "" H 3400 3750 50  0001 C CNN
F 3 "" H 3400 3750 50  0001 C CNN
	1    3400 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5EDD979D
P 3450 800
F 0 "#PWR0102" H 3450 650 50  0001 C CNN
F 1 "+5V" H 3465 973 50  0000 C CNN
F 2 "" H 3450 800 50  0001 C CNN
F 3 "" H 3450 800 50  0001 C CNN
	1    3450 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5EE175FB
P 2300 2550
F 0 "BT1" H 2418 2646 50  0000 L CNN
F 1 "Battery_Cell" H 2418 2555 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x02_P3.81mm_Drill1mm" V 2300 2610 50  0001 C CNN
F 3 "~" V 2300 2610 50  0001 C CNN
	1    2300 2550
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR013
U 1 1 5EE18CF7
P 2900 2000
F 0 "#PWR013" H 2900 1850 50  0001 C CNN
F 1 "+BATT" H 2915 2173 50  0000 C CNN
F 2 "" H 2900 2000 50  0001 C CNN
F 3 "" H 2900 2000 50  0001 C CNN
	1    2900 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5EE196D1
P 2050 2650
F 0 "#PWR06" H 2050 2400 50  0001 C CNN
F 1 "GND" H 2055 2477 50  0000 C CNN
F 2 "" H 2050 2650 50  0001 C CNN
F 3 "" H 2050 2650 50  0001 C CNN
	1    2050 2650
	1    0    0    -1  
$EndComp
$Comp
L power:-BATT #PWR03
U 1 1 5EE19939
P 2050 2400
F 0 "#PWR03" H 2050 2250 50  0001 C CNN
F 1 "-BATT" H 2065 2573 50  0000 C CNN
F 2 "" H 2050 2400 50  0001 C CNN
F 3 "" H 2050 2400 50  0001 C CNN
	1    2050 2400
	1    0    0    -1  
$EndComp
$Comp
L power:-BATT #PWR012
U 1 1 5EE1A56E
P 2300 2650
F 0 "#PWR012" H 2300 2500 50  0001 C CNN
F 1 "-BATT" H 2315 2823 50  0000 C CNN
F 2 "" H 2300 2650 50  0001 C CNN
F 3 "" H 2300 2650 50  0001 C CNN
	1    2300 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 2350 2300 2100
Wire Wire Line
	2050 2400 2050 2650
Wire Wire Line
	2700 2000 2900 2000
NoConn ~ 2700 2200
$Comp
L Switch:SW_DPDT_x2 SW5
U 1 1 5EE2113C
P 2500 2100
F 0 "SW5" H 2500 2385 50  0000 C CNN
F 1 "SW_DPDT_x2" H 2500 2294 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_CuK_JS202011AQN_DPDT_Angled" H 2500 2100 50  0001 C CNN
F 3 "~" H 2500 2100 50  0001 C CNN
	1    2500 2100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW5
U 2 1 5EE223ED
P 3100 900
F 0 "SW5" H 3100 1185 50  0000 C CNN
F 1 "SW_DPDT_x2" H 3100 1094 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_CuK_JS202011AQN_DPDT_Angled" H 3100 900 50  0001 C CNN
F 3 "~" H 3100 900 50  0001 C CNN
	2    3100 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 800  3450 800 
Wire Notes Line
	3250 1650 3250 2950
Wire Notes Line
	3250 2950 1750 2950
Wire Notes Line
	1750 2950 1750 1650
Wire Notes Line
	1750 1650 3250 1650
Wire Notes Line
	1450 500  1450 1600
Wire Notes Line
	1450 1600 3600 1600
Wire Notes Line
	3600 1600 3600 500 
Wire Notes Line
	3600 500  1450 500 
$Comp
L Connector:Barrel_Jack_Switch J1
U 1 1 5EE445EB
P 6250 4700
F 0 "J1" H 6307 5017 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 6307 4926 50  0000 C CNN
F 2 "Connectors:BARREL_JACK" H 6300 4660 50  0001 C CNN
F 3 "~" H 6300 4660 50  0001 C CNN
	1    6250 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J2
U 1 1 5EE4A85A
P 6300 5450
F 0 "J2" H 6357 5917 50  0000 C CNN
F 1 "USB_B_Micro" H 6357 5826 50  0000 C CNN
F 2 "Connectors_USB:USB_Micro-B_Molex-105017-0001" H 6450 5400 50  0001 C CNN
F 3 "~" H 6450 5400 50  0001 C CNN
	1    6300 5450
	1    0    0    -1  
$EndComp
NoConn ~ 6600 5650
Wire Wire Line
	6200 5850 6200 5900
Wire Wire Line
	6200 5900 6250 5900
Wire Wire Line
	6300 5900 6300 5850
$Comp
L power:GND #PWR015
U 1 1 5EE4FB3E
P 6250 6000
F 0 "#PWR015" H 6250 5750 50  0001 C CNN
F 1 "GND" H 6255 5827 50  0000 C CNN
F 2 "" H 6250 6000 50  0001 C CNN
F 3 "" H 6250 6000 50  0001 C CNN
	1    6250 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 6000 6250 5900
Connection ~ 6250 5900
Wire Wire Line
	6250 5900 6300 5900
$Comp
L power:+12V #PWR017
U 1 1 5EE5C716
P 7100 4600
F 0 "#PWR017" H 7100 4450 50  0001 C CNN
F 1 "+12V" H 7115 4773 50  0000 C CNN
F 2 "" H 7100 4600 50  0001 C CNN
F 3 "" H 7100 4600 50  0001 C CNN
	1    7100 4600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR018
U 1 1 5EE5CC8E
P 7200 5250
F 0 "#PWR018" H 7200 5100 50  0001 C CNN
F 1 "+5V" H 7215 5423 50  0000 C CNN
F 2 "" H 7200 5250 50  0001 C CNN
F 3 "" H 7200 5250 50  0001 C CNN
	1    7200 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4600 6650 4600
Wire Wire Line
	6950 4600 7100 4600
$Comp
L power:GND #PWR016
U 1 1 5EE65E7C
P 7100 4800
F 0 "#PWR016" H 7100 4550 50  0001 C CNN
F 1 "GND" H 7105 4627 50  0000 C CNN
F 2 "" H 7100 4800 50  0001 C CNN
F 3 "" H 7100 4800 50  0001 C CNN
	1    7100 4800
	1    0    0    -1  
$EndComp
NoConn ~ 3250 3750
$Comp
L power:+3.3V #PWR014
U 1 1 5EE72401
P 3100 3750
F 0 "#PWR014" H 3100 3600 50  0001 C CNN
F 1 "+3.3V" H 3115 3923 50  0000 C CNN
F 2 "" H 3100 3750 50  0001 C CNN
F 3 "" H 3100 3750 50  0001 C CNN
	1    3100 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:D D1
U 1 1 5EE8702B
P 6800 4600
F 0 "D1" H 6800 4383 50  0000 C CNN
F 1 "D" H 6800 4474 50  0000 C CNN
F 2 "Diodes_SMD:D_SMA" H 6800 4600 50  0001 C CNN
F 3 "~" H 6800 4600 50  0001 C CNN
	1    6800 4600
	-1   0    0    1   
$EndComp
Wire Wire Line
	6550 4800 7100 4800
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 5EE3CD6E
P 7650 5450
F 0 "J3" H 7730 5442 50  0000 L CNN
F 1 "Conn_01x04" H 7730 5351 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x04_P3.81mm_Drill1mm" H 7650 5450 50  0001 C CNN
F 3 "~" H 7650 5450 50  0001 C CNN
	1    7650 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 5850 7450 5850
Connection ~ 6300 5850
Wire Wire Line
	6600 5550 7450 5550
Wire Wire Line
	6600 5450 7450 5450
Wire Wire Line
	7450 5350 7200 5350
Wire Wire Line
	7200 5350 7200 5250
Wire Wire Line
	7450 5650 7450 5850
Text Label 6600 5450 0    50   ~ 0
USBD+
Text Label 6600 5550 0    50   ~ 0
USBD-
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5EE50B8F
P 3100 2400
F 0 "J4" H 3018 2075 50  0000 C CNN
F 1 "Conn_01x02" H 3018 2166 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x02_P3.81mm_Drill1mm" H 3100 2400 50  0001 C CNN
F 3 "~" H 3100 2400 50  0001 C CNN
	1    3100 2400
	1    0    0    1   
$EndComp
Wire Wire Line
	2900 2000 2900 2300
Connection ~ 2900 2000
Wire Wire Line
	2300 2650 2900 2650
Wire Wire Line
	2900 2650 2900 2400
Connection ~ 2300 2650
$Comp
L Device:D D2
U 1 1 5EE62A33
P 6850 5250
F 0 "D2" H 6850 5033 50  0000 C CNN
F 1 "D" H 6850 5124 50  0000 C CNN
F 2 "Diodes_SMD:D_SMA" H 6850 5250 50  0001 C CNN
F 3 "~" H 6850 5250 50  0001 C CNN
	1    6850 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6600 5250 6700 5250
Wire Wire Line
	7000 5250 7200 5250
Connection ~ 7200 5250
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5EE693F5
P 8900 4400
F 0 "H1" H 9000 4449 50  0000 L CNN
F 1 "MountingHole_Pad" H 9000 4358 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 8900 4400 50  0001 C CNN
F 3 "~" H 8900 4400 50  0001 C CNN
	1    8900 4400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5EE69DE3
P 9100 4400
F 0 "H2" H 9200 4449 50  0000 L CNN
F 1 "MountingHole_Pad" H 9200 4358 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9100 4400 50  0001 C CNN
F 3 "~" H 9100 4400 50  0001 C CNN
	1    9100 4400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5EE6A022
P 9300 4400
F 0 "H3" H 9400 4449 50  0000 L CNN
F 1 "MountingHole_Pad" H 9400 4358 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9300 4400 50  0001 C CNN
F 3 "~" H 9300 4400 50  0001 C CNN
	1    9300 4400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5EE6A268
P 9500 4400
F 0 "H4" H 9600 4449 50  0000 L CNN
F 1 "MountingHole_Pad" H 9600 4358 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 9500 4400 50  0001 C CNN
F 3 "~" H 9500 4400 50  0001 C CNN
	1    9500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 4500 9100 4500
Wire Wire Line
	9100 4500 9300 4500
Connection ~ 9100 4500
Wire Wire Line
	9300 4500 9500 4500
Connection ~ 9300 4500
$Comp
L power:GND #PWR019
U 1 1 5EE6F33F
P 8900 4500
F 0 "#PWR019" H 8900 4250 50  0001 C CNN
F 1 "GND" H 8905 4327 50  0000 C CNN
F 2 "" H 8900 4500 50  0001 C CNN
F 3 "" H 8900 4500 50  0001 C CNN
	1    8900 4500
	1    0    0    -1  
$EndComp
Connection ~ 8900 4500
Text Notes 9550 1050 0    50   ~ 0
Green:  75mA@3,30V ->   0R\nBlue:     3mA@2,65V -> 220R\nYellow:  11mA@2,00V -> 120R\nRed:    11mA@2,00V -> 120R\n\nPull-up: 4k7 -> 0,7mA@3,3V
Wire Bus Line
	8200 800  8200 2650
Wire Bus Line
	6700 800  6700 2650
Wire Bus Line
	4550 800  4550 5250
$EndSCHEMATC
