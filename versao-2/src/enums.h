#ifndef ENUMS_H
#define ENUMS_H


/// <summary>
/// Measure mode of Sensor
/// </summary>
enum EMeasureMode {
    EMeasureMode_Unknown = 0,
    EMeasureMode_pH = 1,
    EMeasureMode_Conductivity = 2,
    EMeasureMode_TDS = 3,
    EMeasureMode_ORP = 4,
    EMeasureMode_Salinity = 5,
    EMeasureMode_mV = 6
};

inline const char* ToString(EMeasureMode v)
{
    switch (v)
    {
        case EMeasureMode_pH:   return "MEDIÇÃO DE pH";
        case EMeasureMode_Unknown:   return "[SELECIONE UM MODO DE MEDIÇÃO]";
        case EMeasureMode_ORP:   return "MEDIÇÃO DE ORP(mV)";
        case EMeasureMode_Salinity:   return "MEDIÇÃO DE SALINIDADE";
        case EMeasureMode_TDS:   return "MEDIÇÃO DE TDS";
        case EMeasureMode_mV:   return "MEDIÇÃO DE mV";
        case EMeasureMode_Conductivity:   return "MEDIÇÃO DE CONDUTIVIDADE";
        default: return "[SELECIONE UM MODO DE MEDIÇÃO]";
    }
}

/// <summary>
/// Unit of measure
/// </summary>
enum EMeasureUnit {
    EMeasureUnit_Unknown = 0,
    EMeasureUnit_ppt = 1,
    EMeasureUnit_ppm = 2,
    EMeasureUnit_mgl = 3,
    EMeasureUnit_mS = 4,
    EMeasureUnit_us = 5,
    EMeasureUnit_kPA = 6,
    EMeasureUnit_mmHg = 7,
    EMeasureUnit_pH = 8,
    EMeasureUnit_mV = 9,
};

inline const char* ToString(EMeasureUnit v)
{
    switch (v)
    {
        case EMeasureUnit_ppt: return "PPT";
        case EMeasureUnit_ppm: return "PPM";
        case EMeasureUnit_mgl: return "mg/l";
        case EMeasureUnit_mS: return "mS";
        case EMeasureUnit_us: return "µs";
        case EMeasureUnit_kPA: return "kPA";
        case EMeasureUnit_mmHg: return "mmHg";
        case EMeasureUnit_pH: return "pH";
        case EMeasureUnit_mV: return "mV";
        default:      return "[Unknown Measure Mode]";
    }
}

enum ESensorType {
    ESensorType_Unknown = 0,
    ESensorType_86501_551 = 1,
    ESensorType_86502_552 = 2,
    ESensorType_86503_553 = 3,
    ESensorType_86504_554 = 4,
    ESensorType_86505_555 = 5,
};

inline const char* ToString(ESensorType v)
{
    switch (v)
    {
        case ESensorType_Unknown:   return "[SELECIONE UM TIPO DE SENSOR]";
        case ESensorType_86501_551:   return "86501/551";
        case ESensorType_86502_552:   return "86502/552";
        case ESensorType_86503_553:   return "86503/553";
        case ESensorType_86504_554:   return "86504/554";
        case ESensorType_86505_555:   return "86505/555";
        default:      return "[SELECIONE UM MODO DE MEDIÇÃO]";
    }
}

#endif // ENUMS_H
