#ifndef _WAGTER_CLIMATE_CONTROLLER_RANGE_h
#define _WAGTER_CLIMATE_CONTROLLER_RANGE_h

#include <Arduino.h>

/**
 * A range between two float values
 * 
 * @author Joris Wagter <joris@wagter.net>
 */
class Range
{
    private:

        /**
         * The minimum value of the range
         */
        float min;

        /**
         * The maximum value of the range
         */
        float max;

    public:

        /**
         * Range constructor
         * 
         * @param _min the minimum value of the range
         * @param _max the maximum value of the range
         */
        Range( float _min, float _max );

        /**
         * Get the minimum value of the range
         * 
         * @return the minimum value of the range
         */
        float getMin() const;

        /**
         * Get the maximum value of the range
         * 
         * @return the maximum value of the range
         */
        float getMax() const;

        /**
         * Check if a value is within the range
         * 
         * @param the value to check
         * @return true if the value is within the range, false if the value is not within the range
         */
        bool inRange(float number) const;
};

#endif