[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
**Constructor** -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)
# Constructor
## Description
The constructor creates an instance of the class. This code is usually placed at the top of your sketch before `setup()`.

The constructor only needs to be called when you are including `MAX1704X.H`. If you include the file `MAX17043.H` or `MAX17044.H` the constructor has already been called in those files. You only need to use the `FuelGauge` object. You will need to call one of the [begin() methods](https://porrey.github.io/max1704x/initialization) (for example, `FuelGauge.begin()`).
## Syntax
`MAX1704X(voltageIncrement)`

## Parameters
The first parameter of the constructor specifies the voltage increment (or resolution) for the built-in ADC.

`voltageIncrement: float`

Battery voltage is measured at the cell pin input with respect to GND over a 0 to 5.00V range for the MAX17043 and 0 to 10.00V for the MAX17044 with solutions of 1.25mV and 2.50mV, respectively.

Constants are defined for the MAX17403 and MAX17404 and can be used in the constructor.

* MAX17043_mV: 1.25 mV
* MAX17044_mV: 2.50 mV

## Returns
Nothing
## Example
The code snippet below shows how to create an instance of the library for a MAX17403 with 1.25 mV resolution.

`MAX1704X _fuelGauge = MAX1704X(MAX17043_mV);`

or

`MAX1704X _fuelGauge(MAX17043_mV);`

[**Next Step**](https://porrey.github.io/max1704x/initialization)

## Notes
None