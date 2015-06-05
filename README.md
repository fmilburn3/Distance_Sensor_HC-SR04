# Distance_Sensor_HC-SR04
HC-SR04 Ultrasonic Distance Sensor Example

Demonstrates sensing distance with the HC-SR04 using Texas Instruments LaunchPads / Energia and shows the results on the serial monitor.

This sensor can give unexpected results under certain circumstances.  Among them...
* Sensor is not perpendicular to object and echo is reflecting elsewhere
* Sensor is too close to floor or other object that is reflecting back instead of the intended object
* Object is too small / narrow
* Object is too close or too far away
* Object is not in sensor field
* Sometimes the results are just spurious.... take multiple readings

It can be fairly accurate (depending on your needs), but the coarseness of the beam limits resolution.  It's a inexpensive little sensor that works well for the cost - have fun with it.
