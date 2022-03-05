[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions)

[Basic Initialization](https://porrey.github.io/max1704x/initialization/basic) -
[Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/initialize-wire-yes-no) -
[Custom Address](https://porrey.github.io/max1704x/initialization/custom-address) -
[Custom Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-address-initialize-wire-yes-no) -
Custom Wire -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/custom-wire-address) -
[Custom Wire, Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-wire-address-initialize-wire-yes-no)

# Custom Wire
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