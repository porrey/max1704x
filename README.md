# MAX1704X
Arduino library for the MAX17043 and MAX17044 LiPo Battery Fuel Gauge. For an example of this device on a breakout board see the [SparkFun LiPo Fuel Gauge](https://www.sparkfun.com/products/10617).

![](https://github.com/porrey/max1704x/blob/master/extras/SparkFunLiPoFuelGauge-small.png)

This device is also available on breakout boards from [Amazon](https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=max17043&rh=i%3Aaps%2Ck%3Amax17043).

## Usage ##
The step is to include the library in your sketch. Include MAX17043.h if you are suing the single cell chip or MAX17044.h if you are using the two cell chip.
    
    #include "MAX17043.h"

Next, in the **`setup()`** routine call begin on the Fuel Gauge. Initialize the Serial interface to display the device properties to the serial output.

    void setup()
    {
      // Initialize the serial interface.
      Serial.begin(115200);
    
      // Initialize the fuel gauge.
      FuelGauge.begin();
    }

In the loop, use the properties to show the state of the battery and the fuel gauge.

    void loop()
    {
      // Get the voltage, battery percent
      // and other properties.
      Serial.print("Version:   "); Serial.println(FuelGauge.version());
      Serial.print("ADC:   "); Serial.println(FuelGauge.adc());
      Serial.print("Voltage:   "); Serial.print(FuelGauge.voltage()); Serial.println(" v");
      Serial.print("Percent:   "); Serial.print(FuelGauge.percent()); Serial.println("%");
      Serial.print("Is Sleeping:   "); Serial.println(FuelGauge.isSleeping() ? "Yes" : "No");
      Serial.print("Alert: "); Serial.println(FuelGauge.alertIsActive() ? "Yes" : "No");
      Serial.print("Threshold: "); Serial.println(FuelGauge.getThreshold());
      Serial.print("Compensation:  0x"); Serial.println(FuelGauge.compensation(), HEX);
    }

## Sleep Mode ##
Holding both SDA and SCL logic-low forces the MAX17043/MAX17044 into Sleep mode. While in Sleep mode, all IC operations are halted and power drain of the IC is greatly reduced. After exiting Sleep mode, fuel-gauge operation continues from the point it was halted. SDA and SCL must be held low for at least 2.5s to guarantee transition into Sleep mode. Afterwards, a rising edge on either SDA or SCL immediately transitions the IC out of Sleep mode. 

> Entering Sleep mode does not clear the interrupt.

Alternatively, Sleep mode can be calling the **`sleep()`** method to put the device into sleep mode via software and the **`wake()`** method to take it out of sleep mode. The **`isSleeping()`** method can be used to get the current state of device.

### Entering Seep Mode ###
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


### Exiting Seep Mode ###
The sample code below demonstrates how to check if the device is in sleep mode and then wakes it up if it is.

    if (FuelGauge.isSleeping())
    {
      FuelGauge.wake();
    
      if (!FuelGauge.isSleeping())
      {
    	Serial.println("Fuel Gauge is now awake.");
      }
      else
      {
    	Serial.println("Failed to wake Fuel Gauge.");
      }
    }
    else
    {
      Serial.println("Fuel Gauge is already awake.");
    }

## Resetting the Device ##
Calling the **`reset()`** method causes the MAX17043/MAX17044 to completely reset as if power had been removed. The reset occurs when the last bit has been clocked in. The IC does not respond with an I2C ACK after this command sequence.

    FuelGauge.reset();

## Quick-Start
A quick-start allows the MAX17043/MAX17044 to restart fuel-gauge calculations in the same manner as initial power-up of the IC. For example, if an application’s power-up sequence is exceedingly noisy such that excess error is introduced into the IC’s “first guess” of SOC, the host can issue a quick-start to reduce the error. A quick-start is initiated by a rising edge on the QSTRT pin, or through software by calling the **`quickstart()`** method.

    FuelGauge.quickstart();

## Alert Threshold ##
The MAX17043/MAX17044 have an interrupt feature that alerts a host microprocessor whenever the cell's state of charge, as defined by the SOC register, falls below a predefined alert threshold set at address 0Dh of the CONFIG register. When an alert is triggered, the IC drives the ALRT pin to logic-low and sets the ALRT bit in the CONFIG register to logic 1. The ALRT pin remains logic-low until the host software writes the ALRT bit to logic 0 to clear the interrupt. Clearing the ALRT bit while SOC is below the alert threshold does not generate another interrupt. The SOC register must first rise above and then fall below the alert threshold value before another interrupt is generated. Note that the alert function is not disabled at IC powerup. If the first SOC calculation is below the threshold setting, an interrupt is generated. Entering Sleep mode does not clear the interrupt.

### Check the Alert Status ###
The current status of the alert interrupt can be checked via software. This is done by calling the **`alertIsActive()`** method. See next section for an example of using this method.

### Clear the Alert Status ###
The **`clearAlert()`** method can be called to clear the current alert bit in the config register.

    if (FuelGauge.alertIsActive())
    {
      FuelGauge.clearAlert();
    }

### Change the Alert Threshold ###
The alert threshold is a 5-bit value that sets the state of charge level where an interrupt is generated on the **ALRT** pin. The alert threshold has an LSb weight of 1% and can be programmed from 1% up to 32%. The power-up default value for **ATHD** is 4%.

The **`getThreshold()`** and **`setThresold()`** methods can be used to get the current threshold setting and to change the threshold setting.

    // Decrease the threshold by 1
    uint8_t threshold = FuelGauge.getThreshold();
    FuelGauge.setThreshold(--threshold);

Portions of this document are taken directly from the Maxim data-sheet for the MAX17043/MAX17044. To see the full details the data sheet can be found at [https://datasheets.maximintegrated.com/en/ds/MAX17043-MAX17044.pdf](https://datasheets.maximintegrated.com/en/ds/MAX17043-MAX17044.pdf).