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
[getThreshold()](https://porrey.github.io/max1704x/functions/getThreshold) -
[setThreshold()](https://porrey.github.io/max1704x/functions/setThreshold)

# wake()
Takes the device out sleep mode.

## Parameters
None.

## Returns
`successful : bool`

## Example
The sample code below demonstrates how to check if the device is in sleep mode and then puts it in sleep mode if it is not.

    if (FuelGauge.isSleeping())
    {
      FuelGauge.wake();
    
      if (!FuelGauge.isSleeping())
      {
    	Serial.println("Fuel Gauge has been taken out of sleep mode.");
      }
      else
      {
    	Serial.println("Fuel Gauge failed to be taken out of sleep mode.");
      }
    }
    else
    {
      Serial.println("Fuel Gauge is not in sleep mode.");
    }

## Notes
See also [sleep()](https://porrey.github.io/max1704x/functions/sleep) and [isSleeping()](https://porrey.github.io/max1704x/functions/isSleeping).