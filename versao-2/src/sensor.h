#ifndef SENSOR_H
#define SENSOR_H

#include "measure.h"
#include "Instrumentor.h"

class ISensor
{
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) = 0;
    virtual ESensorType GetSensorType() = 0;
};

#endif // SENSOR_H
