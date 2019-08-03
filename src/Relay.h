#ifndef _WAGTER_CLIMATE_CONTROLLER_RELAY_h
#define _WAGTER_CLIMATE_CONTROLLER_RELAY_h

#include <Arduino.h>

class Relay
{
    protected:
        int pin;
        bool state;

    public:
        Relay(int _pin);
        void begin();
        bool getState();
        void setState(bool _state);
};

#endif