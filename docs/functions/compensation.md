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

# compensation()
## Description
Gets/sets the battery compensation value which adjusts IC performance based on application conditions.

## Parameters
**Get:** `None`

**Set:** `compensation :uint8_t`

## Returns
**Get:** `compensation :uint8_t`

**Set:** `None`

## Example
This snippet of code shows how to get the compensation.

	uint8_t address = FuelGauge. compensation();
	
This snippet of code shows how to set the compensation.

	FuelGauge. compensation(0x097);

## Notes
Compensation can be adjusted to optimize IC performance for different lithium chemistries or different operating temperatures. Contact Maxim for instructions for optimization. The power-up default value for CONFIG is 97h.