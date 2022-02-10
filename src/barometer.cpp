#include "barometer.hpp"

#include <Arduino.h>

namespace mmt {

void init(BMP &bmp)
{
    if (!(bool)bmp.begin()) {
        // return init error
    }
    bmp.setTimeStandby(TIME_STANDBY_2000MS);
    bmp.startNormalConversion();
}

BmpMeasurements measure(BMP &bmp)
{
    BmpMeasurements temp = {0, 0, 0};
    if (!(bool)bmp
             .getMeasurements(temp.temperature, temp.pressure, temp.altitude)) {
        // return measure error
    }
    return temp;
}

void print(const BmpMeasurements &measurements) {}

}  // namespace mmt