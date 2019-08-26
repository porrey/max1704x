/*
 * MAX1704X Arduino Library for MAX17043 and MAX17044 Fuel Gauge.
 *
 * Version 1.0.1
 * Copyright © 2018 Daniel Porrey. All Rights Reserved.
 * https://github.com/porrey/max1704x
 *
 * This file is part of the MAX1704X Arduino Library.
 * 
 * The MAX1704X Arduino Library is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * The MAX1704X Arduino Library is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
 * the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with the MAX1704X Arduino Library. If not, 
 * see http://www.gnu.org/licenses/.
 */
#ifndef MAX1704X_H
#define MAX1704X_H

#include <Arduino.h>
#include <Wire.h>

#define toLowByte(w)              ((uint8_t) ((w) & 0xff))
#define toHighByte(w)             ((uint8_t) ((w) >> 8))
#define toUint16(highB, lowB)     ((uint16_t)((uint8_t)highB << 8) + (uint8_t)lowB)
#define BV(bit)                   (1 <<(bit))
#define setBit(byte, bit)         (byte |= BV(bit))
#define clearBit(byte, bit)       (byte &= ~BV(bit))
#define toggleBit(byte, bit)      (byte ^= BV(bit))

#define I2C_ADDRESS         0x36
#define REGISTER_VCELL      0x02
#define REGISTER_SOC        0x04
#define REGISTER_MODE       0x06
#define REGISTER_VERSION    0x08
#define REGISTER_CONFIG     0x0C
#define REGISTER_COMMAND    0xFE

class MAX1704X
{
  public:
    MAX1704X(float);
    void begin();
    uint16_t adc();
    float voltage();
    float percent();
    uint16_t version();
    uint8_t compensation();
    void compensation(uint8_t data);
    bool sleep();
    bool isSleeping();
    bool wake();
    void reset();
    void quickstart();
    bool alertIsActive();
    void clearAlert();
    uint8_t getThreshold();
    void setThreshold(uint8_t threshold);

  protected:
    float _voltageIncrement;
    uint8_t thresholdToConfig(uint8_t threshold);
    uint8_t configToThreshold(uint8_t config);
    uint16_t readRegister16(uint8_t registerId);
    void writeRegisterId(uint8_t registerId);
    void writeRegister16(uint8_t registerId, uint16_t data);
};
#endif
