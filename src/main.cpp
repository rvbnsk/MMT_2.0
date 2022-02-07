#include <Arduino.h>

#include "barometer.hpp"

constexpr int baud_rate = 9600L;

BMP280_DEV bmp(mmt::sda, mmt::scl);

void setup() { Serial.begin(baud_rate); }

void loop() {}