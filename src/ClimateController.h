#ifndef _WAGTER_CLIMATE_CONTROLLER_h
#define _WAGTER_CLIMATE_CONTROLLER_h

#include <Arduino.h>
#include <Lock.h>
#include <Range.h>
#include <Relay.h>
#include <ClimateSensor.h>

class ClimateController
{
    private:
        const ClimateSensor &sensor;
        Relay *relay;
        Lock *lock;
        Range *range;
        float currentValue;

        void update();
        void setState(bool state);

    public:
        ClimateController(const ClimateSensor &_sensor, Relay *_relay, Range *_range, Lock *_lock);
        void poll();
};

#endif
