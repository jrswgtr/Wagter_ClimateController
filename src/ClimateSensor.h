#ifndef _WAGTER_CLIMATE_CONTROLLER_CLIMATE_SENSOR_h
#define _WAGTER_CLIMATE_CONTROLLER_CLIMATE_SENSOR_h

#include <Arduino.h>

/**
 * A base class to read environmental values like temperature or humidity
 * Please extend this class to create an implementation for your favorite sensor
 * 
 * @author Joris Wagter <joris@wagter.net>
 */
class ClimateSensor
{
    protected:

        /**
         * The data pin of the sensor
         */
        uint8_t pin;

    public:

        /**
         * ClimateSensor constructor
         * 
         * @param pin the data pin of the sensor
         */
        ClimateSensor(uint8_t pin);

        /**
         * Get the last read value of the sensor
         */
        virtual float getValue();

        /**
         * Update the value of the sensor
         */
        virtual void update();
};

#endif