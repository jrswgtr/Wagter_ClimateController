#include <ClimateController.h>

/**
 * public:
 */
ClimateController::ClimateController(ClimateSensor *_sensor, Relay *_relay, Range *_range, Lock *_lock)
    : sensor(_sensor), relay(_relay), lock(_lock), range(_range)
    {
    relay->begin();
    update();
}

void ClimateController::poll()
{
    update();
    setState(range->inRange(currentValue));
}

bool ClimateController::getRelayState()
{
    return relay->getState();
}

Range *ClimateController::getRange()
{
    return range;
}

float ClimateController::getCurrentValue()
{
    return currentValue;
}

/**
 * private:
 */
void ClimateController::update()
{
    sensor->update();
    currentValue = sensor->getValue();
}

void ClimateController::setState( bool state )
{
    if (!lock->isLocked() && state) {
        lock->setLocked(true);
        relay->setState(true);
    } else if (lock->isLocked() && !state) {
        relay->setState(false);
        lock->setLocked(false);
    }
}