#include "meter.h"
#include "sensor.h"

class Meter : public IMeter
{
private:
    EMeasureMode m_mode;
    EMeasureUnit m_unit;
    ISensor* m_sensor;

public:

    // Inherited via IMeter
    virtual void SetMode(EMeasureMode mode) override
    {
        m_mode = mode;
    }

    virtual void SetUnit(EMeasureUnit unit) override
    {
        m_unit = unit;
    }

    virtual void SetSensor(ISensor* sensor) override
    {
        m_sensor = sensor;
    }

    virtual IMeasure* GetInstant() override
    {
        IMeasure* measure = m_sensor->GetMeasure(m_mode, m_unit);
        return measure;
    }
};
