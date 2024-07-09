#ifndef SENSOR_H
#define SENSOR_H

#include "isensor.h"

class Sensor_86501_551 : public ISensor {
private:
    ESensorType m_sensor_type = ESensorType_86501_551;
    double lastValue = 0.01;

    double fRand5(double fMin, double fMax);

public:
    Sensor_86501_551() {}
    ~Sensor_86501_551() {}

    bool flag = true;

    virtual IMeasure* GetMeasure(EMeasureMode mode, EMeasureUnit unit) override;
    

    virtual ESensorType GetSensorType() override
    {
        STUDY_PROFILE_FUNCTION();
        return ESensorType::ESensorType_86501_551;
    }
};



#endif // SENSOR_H
