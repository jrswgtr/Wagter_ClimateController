#include <ClimateController.h>

/**
 * public:
 */
ClimateController::ClimateController(const ClimateSensor &_sensor, Relay *_relay, Range *_range, Lock *_lock)
    : sensor(_sensor), relay(_relay), lock(_lock), range(_range)
    {
    relay->begin();
    update();
}

void ClimateController::poll()
{
    update();
    Serial.println(range->getMin());
    Serial.println(range->getMax());
    Serial.println(currentValue);
    Serial.println(range->inRange(currentValue));
    setState(range->inRange(currentValue));
}
/**
 * private:
 */
void ClimateController::update()
{
    sensor.update();
    currentValue = sensor.getValue();
}
void ClimateController::setState( bool state )
{
    if (relay->getState()) {
        Serial.println("relay is on");

    }
    // Serial.println(!lock->isLocked() && state && !relay->getState());
    if (!lock->isLocked() && state) {
        lock->setLocked(true);
        relay->setState(true);
        Serial.println("turn on relay");
    } else if (lock->isLocked() && !state) {
        relay->setState(false);
        lock->setLocked(false);
    }
}
