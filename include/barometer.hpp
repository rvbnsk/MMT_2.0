#ifndef MMT_BAROMETER_HPP
#define MMT_BAROMETER_HPP

#include <BMP280_DEV.h>

#include "result.hpp"

namespace mmt {

constexpr uint16_t sda = 21;
constexpr uint16_t scl = 21;

using BMP = BMP280_DEV;

struct BmpMeasurements {
    float temperature;
    float pressure;
    float altitude;
};

Result<Unit, Error> init(BMP &);
Result<BmpMeasurements, Error> measure(BMP &);
void print(const BmpMeasurements &);

}  // namespace mmt

#endif