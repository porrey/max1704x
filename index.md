# MAX1704X Library
Arduino library for MAX17043/MAX17044 lithium ion battery fuel gauge.

Provides a simple interface for monitoring battery charge levels. Works with any device using the Maxmim MAX17043 or MAX17044 chip such as the SparkFun LiPo Fuel Gauge.

## Overview
Arduino library for the MAX17043 and MAX17044 LiPo Battery Fuel Gauge. For an example of this device on a breakout board see the [SparkFun LiPo Fuel Gauge](https://www.sparkfun.com/products/10617).

![](https://github.com/porrey/max1704x/blob/master/extras/SparkFunLiPoFuelGauge-small.png)

This device is also available on breakout boards from [Amazon](https://www.amazon.com/s/ref=nb_sb_noss_1?url=search-alias%3Daps&field-keywords=max17043&rh=i%3Aaps%2Ck%3Amax17043). Be cautious when ordering these from unknown suppliers. I have read on various forums that some of these do not work properly. I recommend ordering from SparkFun.

## Getting Started
Using the library requires adding a the library header file to your sketch.

If you are using the MAX17043 (single cell battery) device, then add the line shonw below to the top of your sketch.

`#include "MAX17043.h"`

If you are using the MAX17044 (two cell battery) device, then add the line shonw below to the top of your sketch.

`#include "MAX17044.h"`

If you are wish to initalize the library yourself, then add the line shonw below to the top of your sketch.

`#include "MAX1704X.h"`

Additionally, you will need to call the constructor on the class to create an instance.

[Next Step](https://porrey.github.io/max1704x/constructor)




## Functions
bool deviceFound();

uint8_t findFirstDevice();

uint8_t findFirstDevice(uint16_t expectedVersion);

uint8_t address();

void address(uint8_t);

uint16_t adc();

float voltage();

float percent();

float percentN();

uint16_t version();

uint8_t compensation();

void compensation(uint8_t);

bool sleep();

bool isSleeping();

bool wake();

void reset();

void quickstart();

bool alertIsActive();

void clearAlert();

uint8_t getThreshold();

void setThreshold(uint8_t);
