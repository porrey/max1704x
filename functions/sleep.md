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

# sleep()
## Description
Puts the device into sleep mode. While in Sleep mode, all IC operations are halted, and power drain of the IC is greatly reduced. After exiting Sleep mode, fuel-gauge operation continues from the point it was halted.

## Parameters
`None`

## Returns
`successful : bool`

## Example
The sample code below demonstrates how to check if the device is in sleep mode and then puts it in sleep mode if it is not.

    if (!FuelGauge.isSleeping())
    {
      FuelGauge.sleep();
    
      if (FuelGauge.isSleeping())
      {
    	Serial.println("Fuel Gauge put in sleep mode.");
      }
      else
      {
    	Serial.println("Fuel Gauge failed to be put in sleep mode.");
      }
    }
    else
    {
      Serial.println("Fuel Gauge is already in sleep mode.");
    }

## Notes
Entering Sleep mode does not clear the interrupt. See also [wake()](https://porrey.github.io/max1704x/functions/wake) and [isSleeping()](https://porrey.github.io/max1704x/functions/isSleeping).