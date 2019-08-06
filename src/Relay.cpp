#include <Relay.h>

Relay::Relay(int _pin)
{
	pin = _pin;
    state = false;
}
void Relay::begin()
{
	pinMode(pin, OUTPUT);
}
bool Relay::getState()
{
	return state;
}
void Relay::setState(bool _state)
{
    Serial.println(state);

    if (state != _state) {
        state = _state;
        digitalWrite(pin, state);
    }
}