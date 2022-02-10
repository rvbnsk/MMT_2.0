#include <Arduino.h>

#include "barometer.hpp"

constexpr int baud_rate = 9600L;

mmt::BMP bmp(mmt::sda, mmt::scl);

void setup()
{
    Serial.begin(baud_rate);
    mmt::init(bmp);
}

void loop()
{
    const auto bmp_measurements = mmt::measure(bmp);
    mmt::print(bmp_measurements);
}