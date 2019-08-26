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
#include "MAX1704X.h"

MAX1704X::MAX1704X(float voltageIncrement)
{
  this->_voltageIncrement = voltageIncrement;
}

void MAX1704X::begin()
{
  Wire.begin();
}

uint16_t MAX1704X::adc()
{
  // ***
  // *** 12-bit ADC; remove the 4 MSB's
  // ***
  return (uint16_t)(this->readRegister16(REGISTER_VCELL) >> 4);
}

float MAX1704X::voltage()
{
  // ***
  // *** The MAX1704X has a 12-bit ADC measuring 0 to 5 or 10 Volts in differing
  // *** increments.
  // ***
  return (float)(this->adc() * this->_voltageIncrement);
}

float MAX1704X::percent()
{
  // ***
  // *** Read the 16-bit register value
  // ***
  uint16_t value = this->readRegister16(REGISTER_SOC);

  // ***
  // *** The high byte is the percentage.
  // ***
  float percentage = (float)toHighByte(value);

  // ***
  // *** The low byte contains additional resolution of 1/256%.
  // ***
  float fraction = (float)(toLowByte(value) / 256.f);

  return percentage + fraction;
}

uint16_t MAX1704X::version()
{
  return this->readRegister16(REGISTER_VERSION);
}

uint8_t MAX1704X::compensation()
{
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  return toHighByte(value);
}

void MAX1704X::compensation(uint8_t data)
{
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  uint8_t lowByte = toLowByte(value);
  uint16_t newValue = toUint16(data, lowByte);
  this->writeRegister16(REGISTER_CONFIG, newValue);
}

bool MAX1704X::sleep()
{
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  setBit(value, 7);
  this->writeRegister16(REGISTER_CONFIG, value);
}

bool MAX1704X::isSleeping()
{
  // ***
  // *** The sleep bit is bit 7 in the config byte.
  // ***
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  return (value & 0x80);
}

bool MAX1704X::wake()
{
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  clearBit(value, 7);
  this->writeRegister16(REGISTER_CONFIG, value);
}

void MAX1704X::reset()
{
  // ***
  // *** Write the command 0x5400 to the command register.
  // ***
  this->writeRegister16(REGISTER_COMMAND, 0x5400);
}

void MAX1704X::quickstart()
{
  // ***
  // *** Write the command 0x4000 to the mode register.
  // ***
  this->writeRegister16(REGISTER_MODE, 0x4000);
}

bool MAX1704X::alertIsActive()
{
  // ***
  // *** The alert bit is bit 5 in the config byte.
  // ***
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  return (value & 0x20);
}

void MAX1704X::clearAlert()
{
  // ***
  // *** Get the config register value. Bit 5
  // *** contains the alert value.
  // ***
  uint16_t value = this->readRegister16(REGISTER_CONFIG);
  clearBit(value, 5);
  this->writeRegister16(REGISTER_CONFIG, value);
}

uint8_t MAX1704X::getThreshold()
{
  // ***
  // *** Get the config register value. The last 5 bits
  // *** contains the threshold in 2's complement form.
  // ***
  uint16_t config = this->readRegister16(REGISTER_CONFIG);

  // ***
  // *** Use only the last 5 bits of the config.
  // ***
  return configToThreshold(config & 0x001F);
}

void MAX1704X::setThreshold(uint8_t threshold)
{
  // ***
  // *** Get the config register value. The last 5 bits
  // *** contains the threshold in 2's complement form.
  // ***
  uint16_t config = this->readRegister16(REGISTER_CONFIG);
  
  // ***
  // *** Set the last 5 bits to 0.
  // ***
  config &= 0xFFE0;

  // ***
  // *** The value of threshold can be between 1% and 32%.
  // ***
  uint8_t configThreshold = this->thresholdToConfig(threshold);

  // ***
  // *** Combine the threshold with the config.
  // ***
  config = config + configThreshold;

  // ***
  // *** Write the new register value.
  // ***
  this->writeRegister16(REGISTER_CONFIG, config);
}

uint8_t MAX1704X::thresholdToConfig(uint8_t threshold)
{
  return 31 - (constrain(threshold, 1, 32) - 1);
}

uint8_t MAX1704X::configToThreshold(uint8_t config)
{
  return (32 - constrain(config, 0, 31));
}

uint16_t MAX1704X::readRegister16(uint8_t registerId)
{
  this->writeRegisterId(registerId);
  Wire.requestFrom(I2C_ADDRESS, 2);

  uint8_t highByte = Wire.read();
  uint8_t lowByte = Wire.read();

  uint16_t data = toUint16(highByte, lowByte);
  return data;
}

void MAX1704X::writeRegisterId(uint8_t registerId)
{
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(registerId);
  Wire.endTransmission(false);
}

void MAX1704X::writeRegister16(uint8_t registerId, uint16_t data)
{
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write(registerId);
  Wire.write(toHighByte(data));
  Wire.write(toLowByte(data));
  Wire.endTransmission(true);
}
