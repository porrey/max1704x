# Initialization
## Standard Boards
bool begin();

bool begin(bool);

bool begin(bool, uint8_t);

bool begin(uint8_t);

bool begin(TwoWire*);

bool begin(TwoWire*, uint8_t);

bool begin(TwoWire*, bool, uint8_t);

## ESP Boards
bool begin(int, int);

bool begin(int, int, uint8_t);