#include "measure.cpp"
#include "sensor.h"

#include <stdexcept>

class Sensor_86501_551 : public ISensor {
private:
    ESensorType m_sensor_type = ESensor_86501_551;
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override
    {
        // TODO: Implementar adaptador do Sensor
        switch (mode) {
        case EMeasureMode_pH:
            return new Measure(EMeasureMode::EMeasureMode_pH, EMeasureUnit_pH , 4.213);
        case EMeasureMode_Unknown:
            break;
        case EMeasureMode_Conductivity:
            break;
        case EMeasureMode_TDS:
            break;
        case EMeasureMode_ORP:
            break;
        case EMeasureMode_Salinity:
            break;
        default:
            throw std::invalid_argument("Measure mode not implemented");
            break;
        }
    }
};

class Sensor_86502_552 : public ISensor {
private:
    ESensorType m_sensor_type = ESensor_86502_552;

public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override
    {
        return nullptr;
    }
};

class Sensor_86503_553 : public ISensor {
private:
    ESensorType m_sensor_type = ESensor_86503_553;
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override
    {
        return nullptr;
    }
};

class Sensor_86504_554 : public ISensor {
private:
    ESensorType m_sensor_type = ESensor_86504_554;
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override
    {
        return nullptr;
    }
};

class Sensor_86505_555 : public ISensor {
private:
    ESensorType m_sensor_type = ESensor_86505_555;
public:
    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override
    {
        return nullptr;
    }
};
