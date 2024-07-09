#ifndef MEASURE_H
#define MEASURE_H

#include <ctime>
#include "enums.h"
#include "imeasure.h"

#include "Instrumentor.h"


/// <summary>
/// Represents a measurement.
/// </summary>

class Measure : public IMeasure {
public:
    Measure(EMeasureMode mode, EMeasureUnit unit, double value, double temperature);

    // Inherited via IMeasure

    /// <summary>
    /// Get the measure mode.
    /// </summary>
    /// <returns></returns>
    virtual EMeasureMode GetMode() override;
    

    /// <summary>
    /// Get the measure unit.
    /// </summary>
    /// <returns></returns>
    virtual EMeasureUnit GetUnit() override;
    

    /// <summary>
    /// Get the measure value.
    /// </summary>
    /// <returns></returns>
    virtual double GetValue() override;
   

    /// <summary>
    /// Get the measure timestamp.
    /// </summary>
    /// <returns></returns>
    virtual time_t GetTime() override;
    

    virtual double GetTemperature() override;


private:
    /// <summary>
    /// Measure mode.
    /// </summary>
    EMeasureMode m_measureMode;

    /// <summary>
    /// Measure unit.
    /// </summary>
    EMeasureUnit m_measureUnit;

    /// <summary>
    /// Measure value.
    /// </summary>
    double m_value;

    /// <summary>
    ///  Measure timestamp.
    /// </summary>
    time_t m_timestamp;

    /// <summary>
    ///  Measure temperature.
    /// </summary>
    double m_temperature;

};

#endif // MEASURE_H
