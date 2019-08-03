# Wagter ClimateController #

A "climate controlling" libary for Arduino. Can be used to control the climate using sensors and relays.

## ClimateSensor class ##

Because I wanted to make this library without dependencies on other libraries, I created a base class ClimateSensor. There is no concrete implementation.

You have two options:

1. Use my implementation for DHT sensors, Wagter_ClimateSensor_DHT
2. Create your own implementation for any sensor you like
