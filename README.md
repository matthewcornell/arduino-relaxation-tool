# arduino-relaxation-tool
This project contains the code and circuit diagram to create a vibration-based relaxation tool using an Arduino.


# Circuit diagram
There are two motors (one to hold in each hand), and are two simple circuits per motor, one to read the pot and another to drive the motor.

Circuit: TBD, but basically a combination of these:

* Reading a pot: (Reading a Potentiometer (analog input))[https://www.arduino.cc/en/Tutorial/Potentiometer]

* Driving a piezo motor: (Figure 8-8 of the Arduino Cookbook)[https://books.google.com/books?id=raHyKejOBF4C&pg=PA276&lpg=PA276&dq=figure+8-8+connecting+a+vibration+motor&source=bl&ots=gmm0_Rgz7K&sig=LKvfqXUdqfFy6ZoNYdsy1oS8n7M&hl=en&sa=X&ved=0CB8Q6AEwAGoVChMI38mBqpnmxwIVwj4-Ch15Hgby#v=onepage&q=figure%208-8%20connecting%20a%20vibration%20motor&f=false]


Parts:

* Motor: I used something like these: (Micro Vibrating Motor Cell Phone Beam Bristlebot Robot 6x10mm)[http://www.ebay.com/itm/10X-Micro-Vibrating-Motor-Cell-Phone-Beam-Bristlebot-Robot-6x10mm-Arduino-PI-USA-/161237537955?hash=item258a8194a3]

* Pot: Almost any standard 10K Ohm circuit board pot will do.


# Usage
The code treats uses one pot to control tick duration, i.e., how long the motor stays on, and other other pot to control the period, i.e., how fast it switches between motors. Experiment to find a relaxing combination! If you try it with your friends, you might find that different people like very different settings.

