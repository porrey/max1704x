/*
 * MAX1704X Arduino Library for MAX17043 and MAX17044 Fuel Gauge.
 *
 * Version 1.0.0 
 * Copyright © 2018 Daniel Porrey. All Rights Reserved.
 * https://github.com/porrey/max1704x
 *
 * This file is part of the MAX1704X Arduino Library.
 * 
 * The MAX1704X Arduino Library is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * The MAX1704X Arduino Library is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
 * the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with the MAX1704X Arduino Library. If not, 
 * see http://www.gnu.org/licenses/.
 */
#include "MAX17043.h"

// ***
// *** Connections:
// *** 1) Conect SDA pin to A4 on Uno
// *** 2) Connect SCL pin to A5 on Uno
// *** 3) Connect the GND pin to ground on the Uno.
// ***
// *** For other devices lookup the correct i2C
// *** (SDA and SCL) pins.
// ***

void setup()
{
  // ***
  // *** Initialize the serial interface.
  // ***
  Serial.begin(115200);

  // ***
  // *** Initialize the fuel gauge.
  // ***
  FuelGauge.begin();

  // ***
  // *** Display an initial reading.
  // ***
  displayReading();
  Serial.println();
  displayMenu();
}

void loop()
{
  Serial.println("Enter an option in the serial input (M for menu):");

  while (Serial.available() == 0)
  {
    delay(25);
  }

  char c = Serial.read();
  Serial.println();

  switch (c)
  {
    case 'M':
      displayMenu();
      break;
    case 'D':
      displayReading();
      break;
    case 'S':
      sleepMode();
      break;
    case 'W':
      wakeMode();
      break;
    case 'Q':
      quickStart();
      break;
    case 'C':
      clearAlert();
      break;
    case 'R':
      reset();
      break;
    case '+':
      incrementThreshold();
      break;
    case '-':
      decrementThreshold();
      break;
  }

  Serial.println();
}

void displayMenu()
{
  Serial.println("D => Display a reading.");
  Serial.println("S => Enter sleep mode.");
  Serial.println("W => Wake.");
  Serial.println("Q => Quick start.");
  Serial.println("C => Clear alert.");
  Serial.println("R => Reset.");
  Serial.println("+ => Increment threshold.");
  Serial.println("- => Decrement threshold.");
}

void displayReading()
{
  // ***
  // *** Get the voltage, battery percent
  // *** and other properties.
  // ***
  Serial.print("Version:       "); Serial.println(FuelGauge.version());
  Serial.print("ADC:           "); Serial.println(FuelGauge.adc());
  Serial.print("Voltage:       "); Serial.print(FuelGauge.voltage()); Serial.println(" v");
  Serial.print("Percent:       "); Serial.print(FuelGauge.percent()); Serial.println("%");
  Serial.print("Is Sleeping:   "); Serial.println(FuelGauge.isSleeping() ? "Yes" : "No");
  Serial.print("Alert:         "); Serial.println(FuelGauge.alertIsActive() ? "Yes" : "No");
  Serial.print("Threshold:     "); Serial.println(FuelGauge.getThreshold());
  Serial.print("Compensation:  0x"); Serial.println(FuelGauge.compensation(), HEX);
}

void sleepMode()
{
  if (!FuelGauge.isSleeping())
  {
    FuelGauge.sleep();

    if (FuelGauge.isSleeping())
    {
      Serial.println("Fuel Gauge put in sleep mode.");
    }
    else
    {
      Serial.println("Fuel Gauge failed to be put in sleep mode.");
    }
  }
  else
  {
    Serial.println("Fuel Gauge is already in sleep mode.");
  }
}

void wakeMode()
{
  if (FuelGauge.isSleeping())
  {
    FuelGauge.wake();

    if (!FuelGauge.isSleeping())
    {
      Serial.println("Fuel Gauge is now awake.");
    }
    else
    {
      Serial.println("Failed to wake Fuel Gauge.");
    }
  }
  else
  {
    Serial.println("Fuel Gauge is already awake.");
  }
}

void reset()
{
  FuelGauge.reset();
  Serial.println("Fuel Gauge has been reset/rebooted.");
}

void quickStart()
{
  FuelGauge.quickstart();
  Serial.println("Quick start has been initiated on the Fuel Gauge.");
}

void clearAlert()
{
  FuelGauge.clearAlert();
  Serial.println("The alert has been cleared on the Fuel Gauge.");
}

void incrementThreshold()
{
  uint8_t threshold = FuelGauge.getThreshold();
  FuelGauge.setThreshold(++threshold);
  Serial.print("The alert threshold has been incremented to "); Serial.print(FuelGauge.getThreshold()); Serial.println(",");
}

void decrementThreshold()
{
  uint8_t threshold = FuelGauge.getThreshold();
  FuelGauge.setThreshold(--threshold);
  Serial.print("The alert threshold has been decremented to "); Serial.print(FuelGauge.getThreshold()); Serial.println(",");
}
