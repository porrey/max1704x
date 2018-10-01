/*
   MAX1704X Arduino Library for MAX17043 and MAX17044 Fuel Gauge.

   Version 1.0.0
   Copyright © 2018 Daniel Porrey. All Rights Reserved.
   https://github.com/porrey/max1704x

   This file is part of the MAX1704X Arduino Library.

   The MAX1704X Arduino Library is free software: you can redistribute
   it and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   The MAX1704X Arduino Library is distributed in the hope that it
   will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
   the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the MAX1704X Arduino Library. If not,
   see http://www.gnu.org/licenses/.
*/
#include "MAX1704X.h"

// ***
// *** The MAX17043 is a one-cell device with a
// *** a voltage measurement range of 0 to 5 V.
// ***
MAX1704X _fuelGauge1 = MAX1704X(5);

// ***
// *** The MAX17044 is a two-cell device with a
// *** a voltage measurement range of 0 to 10 V.
// ***
MAX1704X _fuelGauge2 = MAX1704X(10);

void setup()
{
  // ***
  // *** Initialize the serial interface.
  // ***
  Serial.begin(115200);

  // ***
  // *** Initialize the fuel gauges.
  // ***
  _fuelGauge1.begin();
  _fuelGauge2.begin();
}

void loop()
{
  // ***
  // *** Display properties from the MAX17043.
  // ***
  Serial.println("MAX17043:");
  displayFuelGauge(_fuelGauge1);
  Serial.println();

  // ***
  // *** Display properties from the MAX17044.
  // ***
  Serial.println("MAX17044:");
  displayFuelGauge(_fuelGauge2);
  Serial.println();

  // ***
  // *** Delay 5 seconds.
  // ***
  delay(5000);
}

void displayFuelGauge(MAX1704X fuelGauge)
{
  // ***
  // *** Get the voltage, battery percent
  // *** and other properties.
  // ***
  Serial.print("Version:       "); Serial.println(fuelGauge.version());
  Serial.print("ADC:           "); Serial.println(fuelGauge.adc());
  Serial.print("Voltage:       "); Serial.print(fuelGauge.voltage()); Serial.println(" v");
  Serial.print("Percent:       "); Serial.print(fuelGauge.percent()); Serial.println("%");
  Serial.print("Is Sleeping:   "); Serial.println(fuelGauge.isSleeping() ? "Yes" : "No");
  Serial.print("Alert:         "); Serial.println(fuelGauge.alertIsActive() ? "Yes" : "No");
  Serial.print("Threshold:     "); Serial.println(fuelGauge.getThreshold());
  Serial.print("Compensation:  0x"); Serial.println(fuelGauge.compensation(), HEX);
}
