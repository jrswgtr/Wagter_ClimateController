#ifndef _WAGTER_CLIMATE_CONTROLLER_CLIMATE_SENSOR_h
#define _WAGTER_CLIMATE_CONTROLLER_CLIMATE_SENSOR_h

#include <Arduino.h>

class ClimateSensor
{
    protected:
        uint8_t pin;

    public:
        ClimateSensor(uint8_t pin);
        virtual float getValue() const;
        virtual void update() const;
};

#endif