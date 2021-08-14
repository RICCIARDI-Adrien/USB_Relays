EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date "2021-08-12"
Rev ""
Comp "(C) Adrien RICCIARDI"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 8400 3550 2000 2000
U 61155432
F0 "Relays" 50
F1 "Relays.sch" 50
$EndSheet
$Sheet
S 8400 900  2000 2000
U 611612DA
F0 "USB" 50
F1 "USB.sch" 50
$EndSheet
$Comp
L MCU_Microchip_PIC16:PIC16F18854-SO U1
U 1 1 6170521F
P 4300 3200
F 0 "U1" H 4450 2450 50  0000 C CNN
F 1 "PIC16F18854-SO" H 4700 2350 50  0000 C CNN
F 2 "Package_SO:SOIC-28W_7.5x17.9mm_P1.27mm" H 4300 2100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/PIC16(L)F18854%20Data%20Sheet_DS40001826C.pdf" H 4600 2600 50  0001 C CNN
	1    4300 3200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J17
U 1 1 6116AD75
P 6350 2300
F 0 "J17" H 6430 2387 50  0000 L CNN
F 1 "JTAG" H 6430 2296 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 6350 2300 50  0001 C CNN
F 3 "~" H 6350 2300 50  0001 C CNN
F 4 "DNP" H 6430 2205 50  0000 L CNN "Populate"
	1    6350 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2700 5150 2700
Wire Wire Line
	5150 2700 5150 2100
Wire Wire Line
	5150 2100 6150 2100
Wire Wire Line
	4800 2600 5050 2600
Wire Wire Line
	5050 2600 5050 2200
Wire Wire Line
	5050 2200 6150 2200
Text Notes 6050 1800 0    50   ~ 0
PICkit 3 standard pinout\nwithout LVP pin.
$Comp
L power:+5V #PWR028
U 1 1 6116F95E
P 5700 2500
F 0 "#PWR028" H 5700 2350 50  0001 C CNN
F 1 "+5V" H 5715 2673 50  0000 C CNN
F 2 "" H 5700 2500 50  0001 C CNN
F 3 "" H 5700 2500 50  0001 C CNN
	1    5700 2500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR027
U 1 1 61170448
P 5450 2500
F 0 "#PWR027" H 5450 2250 50  0001 C CNN
F 1 "GND" H 5455 2327 50  0000 C CNN
F 2 "" H 5450 2500 50  0001 C CNN
F 3 "" H 5450 2500 50  0001 C CNN
	1    5450 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2500 5450 2300
Wire Wire Line
	5450 2300 6150 2300
Wire Wire Line
	6150 2400 5700 2400
Wire Wire Line
	5700 2400 5700 2500
$Comp
L power:GND #PWR032
U 1 1 61175030
P 4300 4100
F 0 "#PWR032" H 4300 3850 50  0001 C CNN
F 1 "GND" H 4305 3927 50  0000 C CNN
F 2 "" H 4300 4100 50  0001 C CNN
F 3 "" H 4300 4100 50  0001 C CNN
	1    4300 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 4100 4300 4000
$Comp
L power:+5V #PWR025
U 1 1 611761E2
P 4300 1600
F 0 "#PWR025" H 4300 1450 50  0001 C CNN
F 1 "+5V" H 4315 1773 50  0000 C CNN
F 2 "" H 4300 1600 50  0001 C CNN
F 3 "" H 4300 1600 50  0001 C CNN
	1    4300 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2400 4300 1650
$Comp
L Device:C C1
U 1 1 6117A433
P 3400 1900
AR Path="/6117A433" Ref="C1"  Part="1" 
AR Path="/611612DA/6117A433" Ref="C?"  Part="1" 
F 0 "C1" H 3285 2037 50  0000 R CNN
F 1 "4.7u" H 3285 1946 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 3438 1750 50  0001 C CNN
F 3 "~" H 3400 1900 50  0001 C CNN
F 4 "25V" H 3285 1855 50  0000 R CNN "Value2"
F 5 "X7R" H 3285 1764 50  0000 R CNN "Value3"
	1    3400 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 6117B1E3
P 3900 1900
AR Path="/6117B1E3" Ref="C2"  Part="1" 
AR Path="/611612DA/6117B1E3" Ref="C?"  Part="1" 
F 0 "C2" H 4015 2037 50  0000 L CNN
F 1 "100n" H 4015 1946 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3938 1750 50  0001 C CNN
F 3 "~" H 3900 1900 50  0001 C CNN
F 4 "25V" H 4015 1855 50  0000 L CNN "Value2"
F 5 "X7R" H 4015 1764 50  0000 L CNN "Value3"
	1    3900 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR026
U 1 1 6117F244
P 3650 2200
F 0 "#PWR026" H 3650 1950 50  0001 C CNN
F 1 "GND" H 3655 2027 50  0000 C CNN
F 2 "" H 3650 2200 50  0001 C CNN
F 3 "" H 3650 2200 50  0001 C CNN
	1    3650 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2050 3400 2150
Wire Wire Line
	3900 2150 3900 2050
Wire Wire Line
	3400 1750 3400 1650
Wire Wire Line
	3400 1650 3900 1650
Wire Wire Line
	3900 1650 3900 1750
Wire Wire Line
	3900 1650 4300 1650
Connection ~ 3900 1650
Connection ~ 4300 1650
Wire Wire Line
	4300 1650 4300 1600
Connection ~ 3650 2150
Wire Wire Line
	3650 2150 3900 2150
Wire Wire Line
	3650 2150 3650 2200
Wire Wire Line
	3400 2150 3650 2150
Text Label 1600 3400 0    50   ~ 0
MCLR
Wire Wire Line
	6150 2500 5900 2500
Text Label 5900 2500 0    50   ~ 0
MCLR
$Comp
L Device:R R19
U 1 1 611929BA
P 2450 3400
AR Path="/611929BA" Ref="R19"  Part="1" 
AR Path="/611612DA/611929BA" Ref="R?"  Part="1" 
F 0 "R19" V 2153 3400 50  0000 C CNN
F 1 "220" V 2244 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 2380 3400 50  0001 C CNN
F 3 "~" H 2450 3400 50  0001 C CNN
F 4 "1%" V 2335 3400 50  0000 C CNN "Value2"
	1    2450 3400
	0    1    1    0   
$EndComp
$Comp
L Device:C C3
U 1 1 61192E0B
P 2150 3700
AR Path="/61192E0B" Ref="C3"  Part="1" 
AR Path="/611612DA/61192E0B" Ref="C?"  Part="1" 
F 0 "C3" H 2035 3837 50  0000 R CNN
F 1 "100n" H 2035 3746 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2188 3550 50  0001 C CNN
F 3 "~" H 2150 3700 50  0001 C CNN
F 4 "25V" H 2035 3655 50  0000 R CNN "Value2"
F 5 "X7R" H 2035 3564 50  0000 R CNN "Value3"
	1    2150 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 6119490A
P 2150 3100
AR Path="/6119490A" Ref="R17"  Part="1" 
AR Path="/611612DA/6119490A" Ref="R?"  Part="1" 
F 0 "R17" H 2219 3009 50  0000 L CNN
F 1 "10K" H 2219 3100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 2080 3100 50  0001 C CNN
F 3 "~" H 2150 3100 50  0001 C CNN
F 4 "1%" H 2219 3191 50  0000 L CNN "Value2"
	1    2150 3100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR031
U 1 1 6119B79A
P 2150 3950
F 0 "#PWR031" H 2150 3700 50  0001 C CNN
F 1 "GND" H 2155 3777 50  0000 C CNN
F 2 "" H 2150 3950 50  0001 C CNN
F 3 "" H 2150 3950 50  0001 C CNN
	1    2150 3950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR029
U 1 1 6119BBA3
P 2150 2850
F 0 "#PWR029" H 2150 2700 50  0001 C CNN
F 1 "+5V" H 2165 3023 50  0000 C CNN
F 2 "" H 2150 2850 50  0001 C CNN
F 3 "" H 2150 2850 50  0001 C CNN
	1    2150 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3250 2150 3400
Connection ~ 2150 3400
Wire Wire Line
	2150 3400 1600 3400
Wire Wire Line
	2150 3400 2150 3550
Wire Wire Line
	2150 3850 2150 3950
Wire Wire Line
	2150 2850 2150 2950
Wire Wire Line
	2600 3400 3800 3400
Wire Wire Line
	2150 3400 2300 3400
Text GLabel 5200 3700 2    50   Input ~ 0
FTDI_TX
Text GLabel 5200 3800 2    50   Output ~ 0
FTDI_RX
Wire Wire Line
	5850 2800 4800 2800
Wire Wire Line
	4800 2900 5850 2900
Text GLabel 3400 2600 0    50   Output ~ 0
RELAY_1
Text GLabel 3400 2700 0    50   Output ~ 0
RELAY_2
Text GLabel 3400 2800 0    50   Output ~ 0
RELAY_3
Text GLabel 3400 2900 0    50   Output ~ 0
RELAY_4
Text GLabel 3400 3000 0    50   Output ~ 0
RELAY_5
Text GLabel 3400 3100 0    50   Output ~ 0
RELAY_6
Text GLabel 3400 3300 0    50   Output ~ 0
RELAY_7
Text GLabel 3400 3200 0    50   Output ~ 0
RELAY_8
Wire Wire Line
	3400 2600 3800 2600
Wire Wire Line
	3800 2700 3400 2700
Wire Wire Line
	3400 2800 3800 2800
Wire Wire Line
	3400 2900 3800 2900
Wire Wire Line
	3800 3000 3400 3000
Wire Wire Line
	3400 3100 3800 3100
Wire Wire Line
	3800 3200 3400 3200
Wire Wire Line
	3400 3300 3800 3300
Text GLabel 3400 3800 0    50   Output ~ 0
RELAY_9
Text GLabel 3400 3700 0    50   Output ~ 0
RELAY_10
Text GLabel 3400 3600 0    50   Output ~ 0
RELAY_11
Text GLabel 3400 3500 0    50   Output ~ 0
RELAY_12
Wire Wire Line
	3400 3500 3800 3500
Wire Wire Line
	3800 3600 3400 3600
Wire Wire Line
	3400 3700 3800 3700
Wire Wire Line
	3800 3800 3400 3800
Text GLabel 5200 3600 2    50   Output ~ 0
RELAY_13
Text GLabel 5200 3500 2    50   Output ~ 0
RELAY_14
Text GLabel 5850 2900 2    50   Output ~ 0
RELAY_15
Text GLabel 5850 2800 2    50   Output ~ 0
RELAY_16
Wire Wire Line
	5200 3800 4800 3800
Wire Wire Line
	5200 3700 4800 3700
Wire Wire Line
	4800 3600 5200 3600
Wire Wire Line
	5200 3500 4800 3500
$Comp
L Device:LED D9
U 1 1 6120E21C
P 6250 3550
F 0 "D9" V 6289 3432 50  0000 R CNN
F 1 "150060BS55040" V 6198 3432 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6250 3550 50  0001 C CNN
F 3 "~" H 6250 3550 50  0001 C CNN
F 4 "Wurth" H 6250 3550 50  0001 C CNN "Manufacturer"
	1    6250 3550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR030
U 1 1 61211B07
P 6250 3800
F 0 "#PWR030" H 6250 3550 50  0001 C CNN
F 1 "GND" H 6255 3627 50  0000 C CNN
F 2 "" H 6250 3800 50  0001 C CNN
F 3 "" H 6250 3800 50  0001 C CNN
	1    6250 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 3800 6250 3700
$Comp
L Device:R R18
U 1 1 61213BD6
P 5550 3300
F 0 "R18" V 5253 3300 50  0000 C CNN
F 1 "240" V 5344 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5480 3300 50  0001 C CNN
F 3 "~" H 5550 3300 50  0001 C CNN
F 4 "5%" V 5435 3300 50  0000 C CNN "Value2"
	1    5550 3300
	0    1    1    0   
$EndComp
NoConn ~ 4800 3000
NoConn ~ 4800 3100
NoConn ~ 4800 3200
Wire Wire Line
	4800 3300 5400 3300
Wire Wire Line
	5700 3300 6250 3300
Wire Wire Line
	6250 3300 6250 3400
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 6117A771
P 2000 5550
F 0 "H2" H 2100 5599 50  0000 L CNN
F 1 "MountingHole_Pad" H 2100 5508 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.5mm_Pad" H 2000 5550 50  0001 C CNN
F 3 "~" H 2000 5550 50  0001 C CNN
F 4 "DNP" H 2000 5550 50  0001 C CNN "Populate"
	1    2000 5550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 6117AF37
P 1000 5550
F 0 "H1" H 1100 5599 50  0000 L CNN
F 1 "MountingHole_Pad" H 1100 5508 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.5mm_Pad" H 1000 5550 50  0001 C CNN
F 3 "~" H 1000 5550 50  0001 C CNN
F 4 "DNP" H 1000 5550 50  0001 C CNN "Populate"
	1    1000 5550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 6117C2B5
P 3000 5550
F 0 "H3" H 3100 5599 50  0000 L CNN
F 1 "MountingHole_Pad" H 3100 5508 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.5mm_Pad" H 3000 5550 50  0001 C CNN
F 3 "~" H 3000 5550 50  0001 C CNN
F 4 "DNP" H 3000 5550 50  0001 C CNN "Populate"
	1    3000 5550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 6117C5A4
P 4000 5550
F 0 "H4" H 4100 5599 50  0000 L CNN
F 1 "MountingHole_Pad" H 4100 5508 50  0000 L CNN
F 2 "MountingHole:MountingHole_4.5mm_Pad" H 4000 5550 50  0001 C CNN
F 3 "~" H 4000 5550 50  0001 C CNN
F 4 "DNP" H 4000 5550 50  0001 C CNN "Populate"
	1    4000 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 5650 1000 5750
Wire Wire Line
	1000 5750 2000 5750
Wire Wire Line
	2000 5750 2000 5650
Wire Wire Line
	2000 5750 2500 5750
Wire Wire Line
	3000 5750 3000 5650
Connection ~ 2000 5750
Wire Wire Line
	3000 5750 4000 5750
Wire Wire Line
	4000 5750 4000 5650
Connection ~ 3000 5750
$Comp
L power:GND #PWR043
U 1 1 6117FD7B
P 2500 5850
F 0 "#PWR043" H 2500 5600 50  0001 C CNN
F 1 "GND" H 2505 5677 50  0000 C CNN
F 2 "" H 2500 5850 50  0001 C CNN
F 3 "" H 2500 5850 50  0001 C CNN
	1    2500 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 5850 2500 5750
Connection ~ 2500 5750
Wire Wire Line
	2500 5750 3000 5750
$EndSCHEMATC
