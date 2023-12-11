#include "measure.h"
#include "enums.h"
#include <ctime>

/// <summary>
/// Represents a measurement.
/// </summary>
class Measure : public IMeasure {
public:
    Measure(EMeasureMode mode, EMeasureUnit unit, double value, double temperature) {
        m_measureMode = mode;
        m_measureUnit = unit;
        m_temperature = temperature;
        m_value = value;
        m_timestamp = time(0);
    }

    // Inherited via IMeasure

    /// <summary>
    /// Get the measure mode.
    /// </summary>
    /// <returns></returns>
    virtual EMeasureMode GetMode() override
    {
        return m_measureMode;
    }

    /// <summary>
    /// Get the measure unit.
    /// </summary>
    /// <returns></returns>
    virtual EMeasureUnit GetUnit() override
    {
        return m_measureUnit;
    };

    /// <summary>
    /// Get the measure value.
    /// </summary>
    /// <returns></returns>
    virtual double GetValue() override
    {
        return m_value;
    };

    /// <summary>
    /// Get the measure timestamp.
    /// </summary>
    /// <returns></returns>
    virtual time_t GetTime() override
    {
        return m_timestamp;
    };

    virtual double GetTemperature() override
    {
        return m_temperature;
    }


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
