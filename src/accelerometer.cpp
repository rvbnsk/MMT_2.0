#include "accelerometer.hpp"

#include <Arduino.h>

namespace mmt {
void init(Accel &accel)
{
    if (!accel.begin(mmt::mpu_address)) {
        // return init error
    }
    accel.setAccelerometerRange(MPU6050_RANGE_16_G);
    accel.setGyroRange(MPU6050_RANGE_500_DEG);
    accel.setFilterBandwidth(MPU6050_BAND_184_HZ);
}

AccelEvent prepare_data(Accel &accel)
{
    AccelEvent temp = {};
    accel.getEvent(&temp.accel, &temp.gyro, &temp.temp);
    return temp;
}

AccelMeasurements measure(Accel &accel)
{
    const auto temp = prepare_data(accel);
    return {
        temp.gyro.gyro.x,  // NOLINT(cppcoreguidelines-pro-type-union-access)
        temp.gyro.gyro.y,  // NOLINT(cppcoreguidelines-pro-type-union-access)
        temp.gyro.gyro.z,  // NOLINT(cppcoreguidelines-pro-type-union-access)
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        temp.accel.acceleration.x,
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        temp.accel.acceleration.y,
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        temp.accel.acceleration.z};
}

void print(const AccelMeasurements &measurements) {}
}  // namespace mmt