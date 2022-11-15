#pragma once

/// <summary>
/// Measure mode of Sensor
/// </summary>
enum EMeasureMode {
    EMeasureMode_Unknown = 0,
    EMeasureMode_pH = 1,
    EMeasureMode_Conductivity = 2,
    EMeasureMode_TDS = 3,
    EMeasureMode_ORP = 4,
    EMeasureMode_Salinity = 5
};

/// <summary>
/// Unit of measure
/// </summary>
enum EMeasureUnit {
    EMeasureUnit_Unknown = 0,
    EMeasureUnit_pH = 1,
    EMeasureUnit_mS = 2,
    EMeasureUnit_mg = 3,
    EMeasureUnit_mV = 4,
    EMeasureUnit_ppt = 5
};

enum ESensorType {
    ESensor_86501_551 = 0,
    ESensor_86502_552 = 1,
    ESensor_86503_553 = 2,
    ESensor_86504_554 = 3,
    ESensor_86505_555 = 4,
};
