#ifndef _WAGTER_CLIMATE_CONTROLLER_h
#define _WAGTER_CLIMATE_CONTROLLER_h

#include <Arduino.h>
#include <Lock.h>
#include <Range.h>
#include <Relay.h>
#include <ClimateSensor.h>

/**
 * A class to control a climate device, based on values from a climate sensor
 * 
 * @author Joris Wagter <joris@wagter.net>
 */
class ClimateController
{
    private:
    
        /**
         * The sensor to read environmental values
         */
        ClimateSensor *sensor;

        /**
         * The relay to switch the climate device on or off
         */
        Relay *relay;

        /**
         * The range of values from the sensor in which the connected climate device should operate
         */
        Range *range;

        /**
         * The lock to prevent certain relays to be on at the same time
         */
        Lock *lock;

        /**
         * The last polled value of the sensor
         */
        float currentValue;

        /**
         * Update the current value from the sensor
         */
        void update();

        /**
         * Set the state of the relay
         * 
         * @param state of the relay
         */
        void setState(bool state);

    public:

        /**
         * ClimateController constructor
         * 
         * @param _sensor the sensor to read environmental values
         * @param _relay the he relay to switch the climate device on or off
         * @param _range the range of values from the sensor in which the connected climate device should operate
         * @param _lock the lock to prevent certain relays to be on at the same time
         */
        ClimateController(ClimateSensor *_sensor, Relay *_relay, Range *_range, Lock *_lock);

        /**
         * Do periodic poll
         */
        void poll();

        /**
         * Get the state of the relay
         * 
         * @return true if the relay is on, false if the relay is off
         */
        bool getRelayState();

        /**
         * Get the range object of the controller
         * 
         * @return the range object of the controller
         */
        Range *getRange();

        /**
         * Get the last polled value of the sensor
         */
        float getCurrentValue();
};

#endif
