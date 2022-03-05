[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions)

[Basic Initialization](https://porrey.github.io/max1704x/initialization/basic) -
Initialize Wire Yes/No -
[Custom Address](https://porrey.github.io/max1704x/initialization/custom-address) -
[Custom Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-address-initialize-wire-yes-no) -
[Custom Wire](https://porrey.github.io/max1704x/initialization/custom-wire) -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/custom-wire-address) -
[Custom Wire, Address and Initialize Wire Yes/No](https://porrey.github.io/max1704x/initialization/custom-wire-address-initialize-wire-yes-no)

# Initialize Wire Yes/No
### Description
Performs a basic initialization of the library buts allows you to specify whether or not a call to `Wire.begin()` is made. If allowed, the default SDA and SCL pins for your board are used.

## Parameters
`initializeWire : bool`

## Returns
`successful: bool`

## Example
	//
	// Initialize Wire
	//
	Wire.begin();
	
	//
	// Initialize the fuel gauge but 
	// do not initialize Wire.
	//
	if (FuelGauge.begin(false))
	{
	    Serial.println("Found device.");
	}
	
## Notes
Making a call `FuelGauge.begin(true)` is functionally equivalent to `FuelGauge.begin()`.

The default fuel gauge address used by the library is 0x36 (`I2C_DEFAULT_ADDRESS`).