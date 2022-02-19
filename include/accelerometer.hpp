#ifndef MMT_ACCELEROMETER_HPP
#define MMT_ACCELEROMETER_HPP

#include <Adafruit_MPU6050.h>

namespace mmt {

constexpr uint8_t mpu_address = 0x68;

using Accel = Adafruit_MPU6050;

struct AccelEvent {
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;
};

struct AccelMeasurements {
    float gyro_x;
    float gyro_y;
    float gyro_z;
    float accel_x;
    float accel_y;
    float accel_z;
};

void init(Accel &);
AccelEvent prepare_data(Accel &);
AccelMeasurements measure(Accel &);
void print(const AccelMeasurements &);

}  // namespace mmt

#endif