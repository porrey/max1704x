[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) - 
[**Initialization**](https://porrey.github.io/max1704x/initialization) - 
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)

Basic Initialization -
[Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/initialize-wire-yes-no) -
[Custom Address](https://porrey.github.io/max1704x/initialization/custom-address) -
[Custom Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-address-initialize-wire-yes-no) -
[Custom Wire](https://porrey.github.io/max1704x/initialization/custom-wire) -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/custom-wire-address) -
[Custom Wire, Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-wire-address-initialize-wire-yes-no)

# Basic Initialization
## Description
Performs a basic initialization of the library which includes calling `Wire.begin()` using the default SDA and SCL pins for your board.

## Parameters
`None`

## Returns
`successful: bool`

## Example
	#include <MAX17043.h>

	void setup()
	{
	  Serial.begin(9600);
	  FuelGauge.begin();
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
	  _fuelGauge.begin();
	}

	void loop()
	{
	  Serial.print("Battery percentage is ");
	  Serial.print(_fuelGauge.percent());
	}

## Notes
The default fuel gauge address used by the library is 0x36 (`I2C_DEFAULT_ADDRESS`).