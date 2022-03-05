[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions)

[Basic Initialization](https://porrey.github.io/max1704x/initialization/basic) -
[Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/initialize-wire-yes-no) -
[Custom Address](https://porrey.github.io/max1704x/initialization/custom-address) -
Custom Address and Initialize Wire Yes/No -
[Custom Wire](https://porrey.github.io/max1704x/initialization/custom-wire) -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/custom-wire-address) -
[Custom Wire, Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-wire-address-initialize-wire-yes-no)

# Custom Address and Initialize Wire Yes/No
## Description
Performs an initialization of the library, using the specified device address, allowing you to also specify whether or not a call to `Wire.begin()` is made. If allowed, the default SDA and SCL pins for your board are used.

## Parameters
`initializeWire : bool`

`address : uint8_t`

## Returns
`successful: bool`

## Example
	#include <MAX17043.h>

	void setup()
	{
	  Serial.begin(9600);

	  //
	  // Initialize Wire.
	  //
	  Wire.begin();
	  
	  //
	  // Initialize the fuel gauge with a device address
	  // of 0x32.
	  //
	  FuelGauge.begin(false, 0x32);
	}

	void loop()
	{
	  Serial.print("Battery percentage is ");
	  Serial.print(_fuelGauge.percent());
	}

or

	#include <MAX1704X.h>

	MAX1704X _fuelGauge = MAX1704X(MAX17043_mV); 

	void setup()
	{
	  Serial.begin(9600);
	  
	  //
	  // Initialize Wire.
	  //
	  Wire.begin();
	  
	  //
	  // Initialize the fuel gauge with a device address
	  // of 0x32.
	  //
	  _fuelGauge.begin(false, 0x32);
	}

	void loop()
	{
	  Serial.print("Battery percentage is ");
	  Serial.print(_fuelGauge.percent());
	}

## Notes
None