#ifndef _WAGTER_CLIMATE_CONTROLLER_LOCK_h
#define _WAGTER_CLIMATE_CONTROLLER_LOCK_h

#include <Arduino.h>

class Lock
{
    private:
        bool locked;

    public:
        bool isLocked();
        void setLocked(bool _locked);
};

#endif