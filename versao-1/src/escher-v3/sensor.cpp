#include "measure.cpp"
#include "sensor.h"

#include <stdexcept>

class Sensor_86501_551 : public ISensor {
private:
    ESensorType m_sensor_type = ESensorType_86501_551;
    double lastValue = 0.01;

    double fRand5(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
public:
    Sensor_86501_551() {}
    ~Sensor_86501_551() {}

    bool flag = true;

    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override
    {
        double value;

        if(flag) {
            value = fRand5(lastValue, lastValue+0.1);

            if(value > 14) {
                flag = false;
            }
        }
        else {
            value = fRand5(lastValue-1, lastValue);
            if(value < 0) {
                flag = true;
            }
        }
        lastValue = value;

        // TODO: Implementar adaptador do Sensor
        switch (mode) {
        case EMeasureMode_pH:
            return new Measure(EMeasureMode::EMeasureMode_pH, EMeasureUnit_pH , value, fRand5(24, 25));
        case EMeasureMode_Unknown:
            return new Measure(EMeasureMode::EMeasureMode_Unknown, EMeasureUnit_pH , 00, fRand5(24, 25));
            break;
        case EMeasureMode_Conductivity:
            return new Measure(EMeasureMode::EMeasureMode_Conductivity, EMeasureUnit_pH , fRand5(0, 10), fRand5(24, 25));
            break;
        case EMeasureMode_TDS:
            return new Measure(EMeasureMode::EMeasureMode_Conductivity, EMeasureUnit_pH , fRand5(0, 10), fRand5(24, 25));
            break;
        case EMeasureMode_ORP:
            return new Measure(EMeasureMode::EMeasureMode_Conductivity, EMeasureUnit_pH , fRand5(0, 10), fRand5(24, 25));
            break;
        case EMeasureMode_Salinity:
            return new Measure(EMeasureMode::EMeasureMode_Conductivity, EMeasureUnit_pH , fRand5(0, 10), fRand5(24, 25));
            break;
        case EMeasureMode_mV:
            return new Measure(EMeasureMode::EMeasureMode_mV, EMeasureUnit_pH , fRand5(-100, 100), fRand5(24, 25));
            break;
        default:
            throw std::invalid_argument("Measure mode not implemented");
            break;
        }
    }

    virtual ESensorType GetSensorType() override
    {
        return ESensorType::ESensorType_86501_551;
    }
};
