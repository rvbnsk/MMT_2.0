#include <Arduino.h>

#include "accelerometer.hpp"
#include "barometer.hpp"

constexpr int baud_rate = 9600L;
constexpr int interval = 2000;

mmt::BMP bmp(mmt::sda, mmt::scl);
mmt::Accel accel;

void setup()
{
    Serial.begin(baud_rate);
    mmt::init(bmp);
    mmt::init(accel);
}

void loop()
{
    const auto bmp_measurements = mmt::measure(bmp);
    // const auto accel_measurements = mmt::measure(accel);
    mmt::print(bmp_measurements.unwrap());
    // mmt::print(accel_measurements);
}