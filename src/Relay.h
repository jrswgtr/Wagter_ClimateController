#ifndef _WAGTER_CLIMATE_CONTROLLER_RELAY_h
#define _WAGTER_CLIMATE_CONTROLLER_RELAY_h

#include <Arduino.h>

/**
 * A basic high-active relay
 * 
 * @author Joris Wagter <joris@wagter.net>
 */
class Relay
{
    protected:

        /**
         * The digital pin to which the relay is connected
         */
        int pin;

        /**
         * The state of the relay
         */
        bool state;

    public:

        /**
         * Relay constructor
         * 
         * @param _pin the digital pin to which the relay is connected
         */
        Relay(int _pin);

        /**
         * Start the relay
         */
        void begin();

        /**
         * Get the state of the relay
         * 
         * @return true if the relay is on, false if the relay is off
         */
        bool getState();

        /**
         * Set the state of the relay
         * 
         * @param _state the state of the relay. true for on, false for off
         */
        void setState(bool _state);
};

#endif