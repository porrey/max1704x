# MAX1704X Library

## Creating

## MAX1704X()
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
