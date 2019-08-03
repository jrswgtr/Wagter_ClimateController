#include <ClimateSensor.h>

ClimateSensor::ClimateSensor(uint8_t pin)
{
    this->pin = pin;
}

float ClimateSensor::getValue() const
{
    return 0.0;
}

void ClimateSensor::update() const
{}