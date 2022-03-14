#include "accelerometer.hpp"

#include <Arduino.h>

namespace mmt {

Result<Unit, Error> init(Accel &accel)
{
    if (!accel.begin(mmt::mpu_address)) {
        return Err<Error>{Error::Disconnected};
    }
    accel.setAccelerometerRange(MPU6050_RANGE_16_G);
    accel.setGyroRange(MPU6050_RANGE_500_DEG);
    accel.setFilterBandwidth(MPU6050_BAND_184_HZ);

    return Ok<Unit>{Unit{}};
}

Result<AccelEvent, Error> prepare_data(Accel &accel)
{
    AccelEvent temp = {};
    if (!accel.getEvent(&temp.accel, &temp.gyro, &temp.temp))
        return Err<Error>{Error::Busy};

    return Ok<AccelEvent>{temp};
}

/* AccelMeasurements measure(Accel &accel)
{
    const auto temp = prepare_data(accel).unwrap();

    return {
        // NOLINTNEXT(cppcoreguidelines-pro-type-union-access)
        temp.gyro.gyro.x,
        // NOLINTNEXT(cppcoreguidelines-pro-type-union-access)
        temp.gyro.gyro.y,
        // NOLINTNEXT(cppcoreguidelines-pro-type-union-access)
        temp.gyro.gyro.z,
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        temp.accel.acceleration.x,
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        temp.accel.acceleration.y,
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        temp.accel.acceleration.z};
} */

void print(const AccelMeasurements &measurements) {}
}  // namespace mmt