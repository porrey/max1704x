[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)

[Basic Example](https://porrey.github.io/max1704x/examples/basic) -
[Find Device](https://porrey.github.io/max1704x/examples/find-device)
# Basic Example

## Description

Demonstrates basic usage of the library.

## Code

	#include "MAX17043.h"
	
	void setup()
	{
	  //
	  // Initialize the serial interface.
	  //
	  Serial.begin(115200);
	  delay(250);
	
	  //
	  // Wait for serial port to connect.
	  //
	  while (!Serial) {}
	  Serial.println("Serial port initialized.\n");
	
	  //
	  // Initialize the fuel gauge.
	  //
	  if (FuelGauge.begin())
	  {
	    //
	    // Reset the device.
	    //
	    Serial.println("Resetting device...");
	    FuelGauge.reset();
	    delay(250);
	
	    //
	    // Issue a quickstart command and wait
	    // for the device to be ready.
	    //
	    Serial.println("Initiating quickstart mode...");
	    FuelGauge.quickstart();
	    delay(125);
	
	    //
	    // Display an initial reading.
	    //
	    Serial.println("Reading device...");
	    Serial.println();
	    displayReading();
	  }
	  else
	  {
	    Serial.println("The MAX17043 device was NOT found.\n");
	    while (true);
	  }
	}
	
	void loop()
	{
	    displayReading();
	    delay(2000);
	}
	
	void displayReading()
	{
	  //
	  // Get the voltage, battery percent
	  // and other properties.
	  //
	  Serial.println("Device Reading:");
	  Serial.print("Address:       0x"); Serial.println(FuelGauge.address(), HEX);
	  Serial.print("Version:       "); Serial.println(FuelGauge.version());
	  Serial.print("ADC:           "); Serial.println(FuelGauge.adc());
	  Serial.print("Voltage:       "); Serial.print(FuelGauge.voltage()); Serial.println(" mV");
	  Serial.print("Percent:       "); Serial.print(FuelGauge.percent()); Serial.println("%");
	  Serial.print("Is Sleeping:   "); Serial.println(FuelGauge.isSleeping() ? "Yes" : "No");
	  Serial.print("Alert:         "); Serial.println(FuelGauge.alertIsActive() ? "Yes" : "No");
	  Serial.print("Threshold:     "); Serial.print(FuelGauge.getThreshold()); Serial.println("%");
	  Serial.print("Compensation:  0x"); Serial.println(FuelGauge.compensation(), HEX);
	  Serial.println();
	}