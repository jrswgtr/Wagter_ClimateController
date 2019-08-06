#ifndef _WAGTER_CLIMATE_CONTROLLER_LOCK_h
#define _WAGTER_CLIMATE_CONTROLLER_LOCK_h

#include <Arduino.h>

/**
 * A basic lock that can either be locked or unlocked
 * 
 * @author Joris Wagter <joris@wagter.net>
 */
class Lock
{
    private:

        /**
         * True if the lock is locked
         */
        bool locked;

    public:

        /**
         * Check if the lock is locked
         * 
         * @return true if the lock is locked, false if the lock is unlocked
         */
        bool isLocked();

        /**
         * Set the lock state
         * 
         * @param _locked true to lock the lock, false to unlock the lock
         */
        void setLocked(bool _locked);
};

/**
 * A lock that can be set with a time delay
 * 
 * @author Joris Wagter <joris@wagter.net>
 */
class DelayedLock: public Lock
{
    private:

        /**
         * The time delay in milliseconds
         */
        long delay;

        /**
         * The time in milliseconds the lock was last locked
         */
        long lastLocked;

        /**
         * The time in milliseconds the lock was last unlocked
         */
        long lastUnlocked;

    public:

        /**
         * DelayedLock constructor
         * 
         * @param _delay time delay in milliseconds
         */
        DelayedLock(long _delay);

        /**
         * Check if the lock is locked
         * 
         * @return true if the lock is locked, false if the lock is unlocked
         */
        bool isLocked();

        /**
         * Set the lock state
         * 
         * @param _locked true to lock the lock, false to unlock the lock
         */
        void setLocked(bool _locked);
};

#endif