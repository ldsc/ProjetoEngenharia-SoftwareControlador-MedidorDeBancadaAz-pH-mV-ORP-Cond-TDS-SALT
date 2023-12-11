#ifndef MEASURE_H
#define MEASURE_H

#endif // MEASURE_H
#pragma once

#include "enums.h"
#include <ctime>
#include <string>

class IMeasure {
public:
    /// <summary>
    /// Get the measure mode.
    /// </summary>
    /// <returns></returns>
    virtual EMeasureMode GetMode() = 0;

    /// <summary>
    /// Get the measure unit.
    /// </summary>
    /// <returns></returns>
    virtual EMeasureUnit GetUnit() = 0;

    /// <summary>
    /// Get the measure value.
    /// </summary>
    /// <returns></returns>
    virtual double GetValue() = 0;

    /// <summary>
    /// Get the measure timestamp.
    /// </summary>
    /// <returns></returns>
    virtual time_t GetTime() = 0;

    /// <summary>
    /// Get the measure as a string.
    /// </summary>
    /// <returns></returns>
    //virtual std::string GetTimeAsString(const std::string& fmt = "%F %T") = 0;
};
