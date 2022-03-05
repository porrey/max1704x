[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions)

[Basic Initialization](https://porrey.github.io/max1704x/initialization/basic) -
[Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/wire-yes-no) -
[Custom Address](https://porrey.github.io/max1704x/initialization/) -
[Custom Wire](https://porrey.github.io/max1704x/initialization/) -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/) -
[Custom Wire, Address and Initialize Yes/No](https://porrey.github.io/max1704x/initialization/)

#Basic Initialization
## Description
Performs a basic initialization of the library which includes calling `Wire.begin()` using the default SDA and SCL pins for your board.

## Parameters
None

## Returns
`successful: bool`

## Example
	//
	// Initialize the fuel gauge.
	//
	if (FuelGauge.begin())
	{
		Serial.println("Found device.");
	}

## Notes
None