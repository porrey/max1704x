[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions)


[SDA/SCL](https://porrey.github.io/max1704x/initialization/sda-scl) -
[SDA/SCL/Address](https://porrey.github.io/max1704x/initialization/sda-scl-address)

# SDA/SCL/Address
## Description
Performs an initialization of the library which includes calling `Wire.begin()` using the specified SDA and SCL pins and address for your board.

## Parameters
`sda : int`

`scl : int`

`address : uint8_t`

## Returns
`successful: bool`

## Example
	#include <MAX17043.h>

	void setup()
	{
	  Serial.begin(9600);
	  FuelGauge.begin(33, 32, 0x32);
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
	  _fuelGauge.begin(33, 32, 0x32);
	}

	void loop()
	{
	  Serial.print("Battery percentage is ");
	  Serial.print(_fuelGauge.percent());
	}

## Notes
None