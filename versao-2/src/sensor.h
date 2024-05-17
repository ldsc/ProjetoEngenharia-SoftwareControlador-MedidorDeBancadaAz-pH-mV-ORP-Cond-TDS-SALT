#ifndef SENSOR_H
#define SENSOR_H

#include "measure.h"
// Declara as funcoes GetMeasure e GetSensorType
class ISensor
{
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) = 0;
    virtual ESensorType GetSensorType() = 0;
};

#endif // SENSOR_H
