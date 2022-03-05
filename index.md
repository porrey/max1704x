# MAX1704X Library
Arduino library for MAX17043/MAX17044 lithium ion battery fuel gauge.

Provides a simple interface for monitoring battery charge levels. Works with any device using the Maxmim MAX17043 or MAX17044 chip such as the SparkFun LiPo Fuel Gauge.

## Getting Started
Using the library requires adding a the library header file to your sketch.

If you are using the MAX17043 (single cell battery) device, then add the line shonw below to the top of your sketch.

#include "MAX17043.h"

If you are using the MAX1704$ (two cell battery) device, then add the line shonw below to the top of your sketch.

#include "MAX17044.h"

MAX1704X()

### Description
### Syntax
### Parameters
float
### Returns
### Example

## Initialization
### Standard Boards
bool begin();

bool begin(bool);

bool begin(bool, uint8_t);

bool begin(uint8_t);

bool begin(TwoWire*);

bool begin(TwoWire*, uint8_t);

bool begin(TwoWire*, bool, uint8_t);

bool deviceFound();

uint8_t findFirstDevice();

uint8_t findFirstDevice(uint16_t expectedVersion);

### ESP Boards
bool begin(int, int);

bool begin(int, int, uint8_t);


## Functions
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
