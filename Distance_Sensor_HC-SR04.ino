/* 
HC-SR04 Ultrasonic Distance Sensor Example
Demonstrates sensing distance with the HC-SR04 using Texas Instruments
LaunchPads.
                
Created by Frank Milburn 5 Jun 2015
Released into the public domain.

Materials:
----------
https://www.addicore.com/Ultrasonic-HC-SR04-Distance-Sensor-Module-p/133.htm
Addicore also has resistors of all sizes.

Theory:
-------
The HC-SR04 works by sending an ultrasonic pulse and then sensing it as it
returns.  With a microcontroller (and the use of the pulseIn function)
it is possible to measure the time the pulse took to travel out, reflect
off an object, and return.  Knowing the speed of sound the distance
to the object can be calculated.

The HC-SR04 needs 5V at Vcc but the digital (Trig) will go high
if it receives 3V3 from a LaunchPad.  However, it sends 5V back (Echo) and
level conversion is required or a LaunchPad pin could be fried.  An
inexpensive way to do one way level conversion of this sort is with
resistors in a voltage divider as shown in the circuit below.

This code should also work with an Arduino Uno but leave the voltage
divider out of the circuit since it is a 5V device also.

Pin and wiring connections:
---------------------------
Sensor    LaunchPad
Vcc       5V
Trig      Pin 5                     This is 3V3 going to the sensor from LP
Echo      Voltage Divider to Pin 8  This 5V signal needs conversion to 3V
GND       GND

Voltage Divider
Sensor                 LaunchPad
Echo -- 10k Ohm --+--  Pin 8        Reduce the sensor voltage down to 3V
                  |
               15k Ohm
                  |
                 GND
*/

const int trigPin = 5;
const int echoPin = 8;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);      
   
  Serial.begin(9600);
  Serial.println("Starting HC-SR04 Test...");  
}

void loop()
{
  long pulseLength;
  long inches;
  long centimeters;
  
  digitalWrite(trigPin, LOW);            // send low to get a clean pulse
  delayMicroseconds(5);                  // let it settle
  digitalWrite(trigPin, HIGH);           // send high to trigger device
  delayMicroseconds(10);                 // let it settle
  
  pulseLength = pulseIn(echoPin, HIGH);  // measure pulse coming back
  
  // Sound travels about 1130 feet/sec at sea level and normal conditions
  // or 13,560 inches/sec.  The pulseIn function is in micro seconds
  // so the speed would then be 0.01356 in / ms.
  
  // Use float if the precision is needed but this example will use integer
  // math for speed.  Then, 1/.001356 = 73.75,  or approx. 74 ms/in.  Since
  // the signal is travelling out and back, we want half the time for 
  // distance.  Therefore divide by 2 and then 74 ms/in (which is divide
  // by 148).  Want centimeters?  The devisor is 58.
  
  inches = pulseLength / 148; 
  centimeters = pulseLength / 58;  
                                    
  Serial.print("Distance = ");
  Serial.print(inches);
  Serial.print(" inches");
  Serial.print("       ");
  Serial.print(centimeters);
  Serial.println(" centimeters");
  delay(1000);
}
