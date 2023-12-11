#pragma once
#include "measure.h"

class IReport
{
public:
    virtual void AddMeasure(IMeasure measure) = 0;
};

