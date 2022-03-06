[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) - 
[**Initialization**](https://porrey.github.io/max1704x/initialization) - 
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)

[deviceFound()](https://porrey.github.io/max1704x/functions/deviceFound) -
[findFirstDevice()](https://porrey.github.io/max1704x/functions/findFirstDevice) -
[address()](https://porrey.github.io/max1704x/functions/address) -
[adc()](https://porrey.github.io/max1704x/functions/adc) -
[voltage()](https://porrey.github.io/max1704x/functions/voltage) -
[percent()](https://porrey.github.io/max1704x/functions/percent) -
[percentN()](https://porrey.github.io/max1704x/functions/percentN) -
[version()](https://porrey.github.io/max1704x/functions/version) -
[compensation()](https://porrey.github.io/max1704x/functions/compensation) -
[sleep()](https://porrey.github.io/max1704x/functions/sleep) -
[isSleeping()](https://porrey.github.io/max1704x/functions/isSleeping) -
[wake()](https://porrey.github.io/max1704x/functions/wake) -
[reset()](https://porrey.github.io/max1704x/functions/reset) -
[quickstart()](https://porrey.github.io/max1704x/functions/quickstart) -
[alertIsActive()](https://porrey.github.io/max1704x/functions/alertIsActive) -
[clearAlert()](https://porrey.github.io/max1704x/functions/clearAlert) -
[threshold()](https://porrey.github.io/max1704x/functions/threshold)

# voltage()
## Description
Computes the voltage based on the current VCELL (ADC) value using the voltage increments passed into the library in the constructor.

## Parameters
`None`

## Returns
`voltage : float`

## Example
This code snippet demonstrates hwo to get the voltage and display it on the serial port.

	float voltage = FuelGauge.voltage();
	Serial.print("The battery voltage is "); Serial.println(voltage);

## Notes
None.