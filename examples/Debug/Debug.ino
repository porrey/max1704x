#include <Wire.h>
#include <Arduino.h>

//
// Macros
//
#define toLowByte(w)              ((uint8_t) ((w) & 0xff))
#define toHighByte(w)             ((uint8_t) ((w) >> 8))
#define toUint16(highB, lowB)     ((uint16_t)((uint8_t)highB << 8) + (uint8_t)lowB)

//
// Device address (use 0x32 for clones).
//
#define DEVICE_ADDRESS 0x32

void setup()
{
  //
  // Initialize the serial interface.
  //
  Serial.begin(115200);

  //
  // Wait for serial port to connect.
  //
  while (!Serial) {}
  Serial.println("Serial port initialized.\n");

  //
  // Initialize Wire.
  //
  Wire.begin();

  //
  // Issue a restart command and wait
  // for the dvice to be ready.
  //
  writeRegister16(DEVICE_ADDRESS, 0xfe, 0x5400);
  delay(250);
  
  //
  // Issue a quickstart command and wait
  // for the dvice to be ready.
  //
  writeRegister16(DEVICE_ADDRESS, 0xfe, 0x4000);
  delay(125);
  
  //
  // Get the device data.
  //
  readDevice();
}

void readDevice()
{
  uint8_t b2 = readRegister8(DEVICE_ADDRESS, 0x02);
  uint8_t b3 = readRegister8(DEVICE_ADDRESS, 0x03);
  uint8_t b4 = readRegister8(DEVICE_ADDRESS, 0x04);
  uint8_t b5 = readRegister8(DEVICE_ADDRESS, 0x05);
  uint8_t b6 = readRegister8(DEVICE_ADDRESS, 0x06);
  uint8_t b7 = readRegister8(DEVICE_ADDRESS, 0x07);
  uint8_t b8 = readRegister8(DEVICE_ADDRESS, 0x08);
  uint8_t b9 = readRegister8(DEVICE_ADDRESS, 0x09);
  uint8_t bc = readRegister8(DEVICE_ADDRESS, 0x0c);
  uint8_t bd = readRegister8(DEVICE_ADDRESS, 0x0d);

  Serial.print("ADDRESS:            0x"); Serial.print(DEVICE_ADDRESS, HEX); Serial.print("\t("); Serial.print(DEVICE_ADDRESS);  Serial.println(")");
  Serial.print("VCELL HIGH BYTE:    0x"); printHex(b2); Serial.print("\t("); Serial.print(b2);  Serial.println(")");
  Serial.print("VCELL LOW BYTE:     0x"); printHex(b3); Serial.print("\t("); Serial.print(b3);  Serial.println(")");
  Serial.print("SOC HIGH BYTE:      0x"); printHex(b4); Serial.print("\t("); Serial.print(b4);  Serial.println(")");
  Serial.print("SOC LOW BYTE:       0x"); printHex(b5); Serial.print("\t("); Serial.print(b5);  Serial.println(")");
  Serial.print("MODE LOW BYTE:      0x"); printHex(b6); Serial.print("\t("); Serial.print(b6);  Serial.println(")");
  Serial.print("MODE LOW BYTE:      0x"); printHex(b7); Serial.print("\t("); Serial.print(b7);  Serial.println(")");
  Serial.print("VERSION LOW BYTE:   0x"); printHex(b8); Serial.print("\t("); Serial.print(b8);  Serial.println(")");
  Serial.print("VERSION LOW BYTE:   0x"); printHex(b9); Serial.print("\t("); Serial.print(b9);  Serial.println(")");
  Serial.print("CONFIG LOW BYTE:    0x"); printHex(bc); Serial.print("\t("); Serial.print(bc);  Serial.println(")");
  Serial.print("CONFIG LOW BYTE:    0x"); printHex(bd); Serial.print("\t("); Serial.print(bd);  Serial.println(")");

  uint16_t adc = toUint16(b2, b3) >> 4;

  Serial.println();
  Serial.print("PERCENT:            "); Serial.print(b4 + (b5 / 256.0)); Serial.println("%");
  Serial.print("ADC:                "); Serial.println(adc);
  Serial.print("VOLTAGE:            "); Serial.print(adc * 1.25); Serial.println(" mV");
}

void loop()
{
}

//
// Ensure a bytes is printed
// with 2 characters.
//
void printHex(uint8_t b)
{
  if (b < 16)
  {
    Serial.print("0");
  }

  Serial.print(b, HEX);
}

void writeRegisterId(uint8_t address, uint8_t registerId)
{
  Wire.beginTransmission(address);
  Wire.write(registerId);
  Wire.endTransmission(false);
}

uint8_t readRegister8(uint8_t address, uint8_t registerId)
{
  writeRegisterId(address, registerId);
  Wire.requestFrom(address, (uint8_t)2);
  return Wire.read();
}

void writeRegister16(uint8_t address, uint8_t registerId, uint16_t data)
{
  Wire.beginTransmission(address);
  Wire.write(registerId);
  Wire.write(toHighByte(data));
  Wire.write(toLowByte(data));
  Wire.endTransmission(true);
}
