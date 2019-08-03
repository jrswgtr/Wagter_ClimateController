#ifndef _WAGTER_CLIMATE_CONTROLLER_RANGE_h
#define _WAGTER_CLIMATE_CONTROLLER_RANGE_h

#include <Arduino.h>

class Range
{
    private:
        float min, max;

    public:
        Range( float _min, float _max );
        float getMin() const;
        float getMax() const;
        bool inRange(float number) const;
};

#endif