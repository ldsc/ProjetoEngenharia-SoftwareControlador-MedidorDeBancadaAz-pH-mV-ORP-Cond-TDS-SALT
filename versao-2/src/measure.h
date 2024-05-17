#ifndef MEASURE_H
#define MEASURE_H

#include <ctime>
#include "enums.h"

// Classe responsavel por criar as funcoes get
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
    /// Get the measure value.
    /// </summary>
    /// <returns></returns>
    virtual double GetTemperature() = 0;

    /// <summary>
    /// Get the measure timestamp.
    /// </summary>
    /// <returns></returns>
    virtual time_t GetTime() = 0;
};

#endif // MEASURE_H
