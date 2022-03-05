[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) - 
[**Initialization**](https://porrey.github.io/max1704x/initialization) - 
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)

[Basic Initialization](https://porrey.github.io/max1704x/initialization/basic) -
[Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/initialize-wire-yes-no) -
[Custom Address](https://porrey.github.io/max1704x/initialization/custom-address) -
[Custom Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-address-initialize-wire-yes-no) -
Custom Wire -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/custom-wire-address) -
[Custom Wire, Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-wire-address-initialize-wire-yes-no)

# Custom Wire
## Description
Performs an initialization of the library specifying the instance of Wire to use.

On boards that support cutom instance of Wire, the custom instance can be passed into the library. This method will NOT call `begin()` on the Wire instance passed.

## Parameters
`wire : TwoWire*`

## Returns
`successful: bool`

## Example
	#include <Wire.h>
	#include <MAX17043.h>

	TwoWire _wire1;

	void setup()
	{
	  Serial.begin(9600);
	  _wire1.begin();
	  FuelGauge.begin(&_wire1);
	}

	void loop()
	{
	  Serial.print("Battery percentage is ");
	  Serial.print(_fuelGauge.percent());
	}

or

	#include <Wire.h>
	#include <MAX1704X.h>

	TwoWire _wire1;
	MAX1704X _fuelGauge = MAX1704X(MAX17043_mV); 

	void setup()
	{
	  Serial.begin(9600);
	  _wire1.begin();
	  _fuelGauge.begin(&_wire1);
	}

	void loop()
	{
	  Serial.print("Battery percentage is ");
	  Serial.print(_fuelGauge.percent());
	}
	
## Notes
The default fuel gauge address used by the library is 0x36 (`I2C_DEFAULT_ADDRESS`).