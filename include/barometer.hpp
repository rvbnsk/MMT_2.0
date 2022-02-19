#ifndef MMT_BAROMETER_HPP
#define MMT_BAROMETER_HPP

#include <BMP280_DEV.h>

namespace mmt {

constexpr uint16_t sda = 21;
constexpr uint16_t scl = 21;

using BMP = BMP280_DEV;

struct BmpMeasurements {
    float temperature;
    float pressure;
    float altitude;
};

void init(BMP &);
BmpMeasurements measure(BMP &);
void print(const BmpMeasurements &);

}  // namespace mmt

#endif