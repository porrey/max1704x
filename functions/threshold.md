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

# getThreshold()
## Description
Gets/sets the alert threshold. The value can be between 1% and 32%. The default is 4%.

## Parameters
**Get:** `None`

**Set:** `threshold :uint8_t`

## Returns
**Get** `threshold : uint8_t`

**Set** `None`

## Example
This snippet of code increments the current threshold value.

	void incrementThreshold()
	{
	  uint8_t threshold = FuelGauge.threshold();
	  FuelGauge.threshold(++threshold);
	  Serial.print("The alert threshold has been incremented to "); Serial.print(FuelGauge.threshold()); Serial.println(",");
	}

## Notes
The MAX17043/MAX17044 have an interrupt feature that alerts a host microprocessor whenever the cell's state of charge, as defined by the SOC register, falls below a predefined alert threshold set at address 0Dh of the CONFIG register. When an alert is triggered, the IC drives the ALRT pin to logic-low and sets the ALRT bit in the CONFIG register to logic 1. The ALRT pin remains logic-low until the host software writes the ALRT bit to logic 0 to clear the interrupt. Clearing the ALRT bit while SOC is below the alert threshold does not generate another interrupt. The SOC register must first rise above and then fall below the alert threshold value before another interrupt is generated. Note that the alert function is not disabled at IC powerup. If the first SOC calculation is below the threshold setting, an interrupt is generated. Entering Sleep mode does not clear the interrupt.

See also [alertIsActive()](https://porrey.github.io/max1704x/functions/alertIsActive), [clearAlert()](https://porrey.github.io/max1704x/functions/clearAlert)