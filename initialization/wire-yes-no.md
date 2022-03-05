[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) - 
**Initialization** - 
[**Functions**](https://porrey.github.io/max1704x/functions)

[Basic Initialization](https://porrey.github.io/max1704x/initialization/basic) -
Initialize Wire Yes/No -
[Custom Address](https://porrey.github.io/max1704x/initialization/) -
[Custom Wire](https://porrey.github.io/max1704x/initialization/) -
[Custom Wire and Address](https://porrey.github.io/max1704x/initialization/) -
[Custom Wire, Address and Initialize Yes/No](https://porrey.github.io/max1704x/initialization/)
#Initialize Wire Yes/No
### Description
Performs a basic initialization of the library buts allows you to specify whether or not a call to `Wire.begin()` is made. If allowed, the default SDA and SCL pins for your board are used.

### Parameters
`initializeWire : bool`

### Returns
`successful: bool`

### Example
	//
	// Initialize Wire
	//
	Wire.begin();
	
	//
	// Initialize the fuel gauge.
	//
	if (FuelGauge.begin(false))
	{
		Serial.println("Found device.");
	}
	
### Notes
Making a call `FuelGauge.begin(true)` is functionally equivalent to `FuelGauge.begin()`.