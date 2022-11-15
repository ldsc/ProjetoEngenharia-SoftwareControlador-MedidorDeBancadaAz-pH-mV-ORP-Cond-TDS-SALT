#pragma once
#include "enums.h"
#include "sensor.h"

class IMeter
{
public:
    virtual void SetMode(EMeasureMode mode) = 0;
    virtual void SetUnit(EMeasureUnit unit) = 0;
    virtual void SetSensor(ISensor* sensor) = 0;
    virtual IMeasure* GetInstant() = 0;

    virtual void StartLog() = 0;
    virtual void StopLog() = 0;
};
