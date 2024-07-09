#ifndef ISENSOR_H
#define ISENSOR_H

#include "measure.h"

class ISensor
{
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) = 0;
    virtual ESensorType GetSensorType() = 0;
};

#endif // SENSOR_H