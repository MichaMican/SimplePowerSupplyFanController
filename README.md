# SimplePowerSupplyFanController

## What it does:
This Arduino program uses a temperature sensor to controll the speed of a fan, which was used to cool a powersupply of a private server project. The program also triggers a buzzer alarm if the temperature rises to a certain threshold

## How to Setup:
1.  Open in Arduino IDE or other IDE, which is capable of flashing an Arduino
1.  Maybe it's necessary to adjust the formular for calculating the temperature (See datasheet of temperature sensor)
1.  Set the correct thermistorpin, buzzerpin and fanpin
1.  Set the Alarmthreshold - If the temperature exceeds this threshold the alarm starts
