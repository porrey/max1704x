[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)

[Basic Example](https://porrey.github.io/max1704x/examples/basic) -
[Find Device](https://porrey.github.io/max1704x/examples/find-device)
# Find Device

## Description

Demonstrates how to search the i2c bus for a device.

## Code
	#include "MAX1704X.h"
	
	//
	// Define the MAX17403 fuel gauge. Use MAX17044_mV
	// for the MAX17044.
	//
	MAX1704X _fuelGauge = MAX1704X(MAX17043_mV);
	
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
	  // Initialize the fuel gauge without an address.
	  //
	  Serial.println("Initializing the fuel gauge instance.");
	  _fuelGauge.begin(DEFER_ADDRESS);
	
	  //
	  // Find a connected fuel gauge on the i2c bus.
	  //
	  Serial.println("Searching for device...");
	  uint8_t deviceAddress = _fuelGauge.findFirstDevice();
	
	  //
	  // If a device is NOT found, the address returned will be 0.
	  //
	  if (deviceAddress > 0)
	  {
	    //
	    // Set the device address.
	    //
	    _fuelGauge.address(deviceAddress);
	    Serial.print("A MAX17043 device was found at address 0x"); Serial.println(_fuelGauge.address(), HEX);
	
	    //
	    // Reset the device.
	    //
	    Serial.println("Resetting device...");
	    _fuelGauge.reset();
	    delay(250);
	
	    //
	    // Issue a quickstart command and wait
	    // for the device to be ready.
	    //
	    Serial.println("Initiating quickstart mode...");
	    _fuelGauge.quickstart();
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
	    Serial.println("A MAX17043 device was not found!");
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
	  Serial.print("Address:       0x"); Serial.println(_fuelGauge.address(), HEX);
	  Serial.print("Version:       "); Serial.println(_fuelGauge.version());
	  Serial.print("ADC:           "); Serial.println(_fuelGauge.adc());
	  Serial.print("Voltage:       "); Serial.print(_fuelGauge.voltage()); Serial.println(" mV");
	  Serial.print("Percent:       "); Serial.print(_fuelGauge.percent()); Serial.println("%");
	  Serial.print("Is Sleeping:   "); Serial.println(_fuelGauge.isSleeping() ? "Yes" : "No");
	  Serial.print("Alert:         "); Serial.println(_fuelGauge.alertIsActive() ? "Yes" : "No");
	  Serial.print("Threshold:     "); Serial.print(_fuelGauge.getThreshold()); Serial.println("%");
	  Serial.print("Compensation:  0x"); Serial.println(_fuelGauge.compensation(), HEX);
	  Serial.println();
	}