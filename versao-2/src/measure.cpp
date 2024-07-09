#include "measure.h"
#include <ctime>

Measure::Measure(EMeasureMode mode, EMeasureUnit unit, double value, double temperature)
{
    STUDY_PROFILE_FUNCTION();
    m_measureMode = mode;
    m_measureUnit = unit;
    m_temperature = temperature;
    m_value = value;
    m_timestamp = time(0);
}

EMeasureMode Measure::GetMode()
{
    STUDY_PROFILE_FUNCTION();
    return m_measureMode;
}

EMeasureUnit Measure::GetUnit()
{
    STUDY_PROFILE_FUNCTION();
    return m_measureUnit;
};

double Measure::GetValue()
 {
    STUDY_PROFILE_FUNCTION();
    return m_value;
}
time_t Measure::GetTime()
{
    STUDY_PROFILE_FUNCTION();
    return m_timestamp;
}
double Measure::GetTemperature()
{
    STUDY_PROFILE_FUNCTION();
    return m_temperature;
}