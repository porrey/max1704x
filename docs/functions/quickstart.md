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

# quickstart()
## Description
A quick-start allows the MAX17043/MAX17044 to restart fuel-gauge calculations in the same manner as initial power-up of the IC. For example, if an application’s power-up sequence is exceedingly noisy such that excess error is introduced into the IC’s “first guess” of SOC, the host can issue a quick-start to reduce the error. A quick-start is initiated by a rising edge on the QSTRT pin, or through software by calling the quickstart() method.

## Parameters
None.

## Returns
None.

## Example
This snippet of code shows how to reset the quickstart and wait for it to complete.

    //
    // Issue a quickstart command and wait
    // for the device to be ready.
    //
    Serial.println("Initiating quickstart mode...");
    FuelGauge.quickstart();
    delay(125);

## Notes
None.