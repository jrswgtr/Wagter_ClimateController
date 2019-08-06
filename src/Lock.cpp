#include <Lock.h>

bool Lock::isLocked()
{
    return locked;
}
void Lock::setLocked(bool _locked)
{
    locked = _locked;
}

DelayedLock::DelayedLock(long _delay)
{
    delay = _delay;
}

void DelayedLock::setLocked(bool _locked)
{
    long currentTime = millis();
    if (_locked) {
        lastLocked = currentTime;
    } else {
        lastUnlocked = currentTime;
    }

    Lock::setLocked(_locked);
}

bool DelayedLock::isLocked()
{
    long currentTime = millis();
    if (!Lock::isLocked() && currentTime <= lastUnlocked + delay) {
        Serial.println("Lock is unlocked but delay is not over.");
        return false;
    }

    return Lock::isLocked();
}