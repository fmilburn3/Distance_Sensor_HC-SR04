# Distance_Sensor_HC-SR04
HC-SR04 Ultrasonic Distance Sensor Example

Demonstrates sensing distance with the HC-SR04 using Texas Instruments LaunchPads / Energia and shows the results on the serial monitor.

This sensor can give unexpected results under certain circumstances.  Among them...
* Sensor is not perpendicular to object and echo is reflecting elsewhere
* Surface sensor is aimed at is a poor reflector or is irregular
* Sensor is too close to floor or other object that is reflecting back instead of the intended object
* Object is too small / narrow
* Object is too close or too far away
* Object is not in sensor field
* Sometimes the results are just spurious.... take multiple readings

See the Wiki for a photo showing how easy it can be to set up.

There is a datasheet with the beam pattern here: http://www.robot-electronics.co.uk/htm/sonar_faq.htm

It can be fairly accurate (depending on your needs), but the wide beam limits resolution for many objects.  It's a inexpensive little sensor that works well for the cost - have fun with it.

Ideas for further development:
1) Attach it to a servo and scan with it
2) Set up an array of them to see in multiple directions
