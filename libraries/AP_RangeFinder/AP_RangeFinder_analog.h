#pragma once

#include "RangeFinder.h"
#include "RangeFinder_Backend.h"
#include "AP_RangeFinder_Params.h"

class AP_RangeFinder_analog : public AP_RangeFinder_Backend
{
public:
    // constructor
    AP_RangeFinder_analog(RangeFinder::RangeFinder_State &_state, AP_RangeFinder_Params &_params);

    // static detection function
    static bool detect(AP_RangeFinder_Params &_params);

    // update state
    void update(void) override;

//OW
    static const struct AP_Param::GroupInfo var_info[];

private:
    //use this different notation to avoid name overlap
    AP_Int8 pPin;
    AP_Int8 pRatiometric;
    AP_Int8  pStop_pin;
    AP_Int16 pSettle_time_ms;
    AP_Float pScaling;
    AP_Float pOffset;
    AP_Int8 pFunction;
//OWEND

protected:

    MAV_DISTANCE_SENSOR _get_mav_distance_sensor_type() const override {
        return MAV_DISTANCE_SENSOR_UNKNOWN;
    }

private:
    // update raw voltage
    void update_voltage(void);

    AP_HAL::AnalogSource *source;
};
