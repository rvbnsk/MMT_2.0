#include "barometer.hpp"

#include <Arduino.h>

namespace mmt {

Result<Unit, Error> init(BMP &bmp)
{
    if (!(bool)bmp.begin()) { return Err<Error>{Error::Disconnected}; }
    bmp.setTimeStandby(TIME_STANDBY_2000MS);
    bmp.startNormalConversion();
    return Ok<Unit>{Unit{}};
}

Result<BmpMeasurements, Error> measure(BMP &bmp)
{
    BmpMeasurements temp = {0, 0, 0};
    if (!(bool)bmp
             .getMeasurements(temp.temperature, temp.pressure, temp.altitude)) {
        return Err<Error>{Error::Busy};
    }
    return Ok<BmpMeasurements>{temp};
}

void print(const BmpMeasurements &measurements)
{
    Serial.println(measurements.altitude);
}

}  // namespace mmt