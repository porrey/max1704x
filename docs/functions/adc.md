[**Home**](https://porrey.github.io/max1704x) -
[**Getting Started**](https://porrey.github.io/max1704x/getting-started) -
[**Constructor**](https://porrey.github.io/max1704x/constructor) - 
[**Initialization**](https://porrey.github.io/max1704x/initialization) - 
[**Functions**](https://porrey.github.io/max1704x/functions) -
[**Examples**](https://porrey.github.io/max1704x/examples)

[[deviceFound()](https://porrey.github.io/max1704x/functions/deviceFound) -
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

# adc()
## Description
Reads the value from the VCELL register on the device. This value reports the 12-bit A/D measurement of battery voltage.

## Parameters
`None`

## Returns
`value : uint16_t`

## Example
This snippet of code shows how to calculate the voltage of the battery using the ADC value on a one cell battery.

	uint16_t value = FuelGauge.adc();
	float voltage = value * 1.25;

## Notes
None.