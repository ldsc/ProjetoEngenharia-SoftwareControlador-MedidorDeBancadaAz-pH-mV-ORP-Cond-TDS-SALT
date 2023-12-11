#pragma once

#include "enums.h"
#include "measure.h"

class ISensor
{
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) = 0;
    virtual ESensorType GetSensorType() = 0;
};

