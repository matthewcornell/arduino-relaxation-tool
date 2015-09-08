# arduino-relaxation-tool
This project contains the code and circuit diagram to create a simple vibration-based relaxation tool using an Arduino.
The tool has two small motors (like the ones in cell phones) that you hold in each hand (one motor per hand). The motors
are alternately pulsed back and forth between the left and right hands, with two potentiometers controlling how long
each motor stays on, and the delay between switching. Experiment to find a relaxing combination! If you try it with your
friends, you might find that different people like very different settings.


# Circuit
This is basically a mashup of two standard Arduino projects - reading analog values from a pot, and controlling a piezo
motor. The circuits are duplicated for left and right sides. The circuit diagram is
[here](https://github.com/matthewcornell/arduino-relaxation-tool/blob/master/circuit-diagram.jpg), and a picture of the
assembled board is [here](https://github.com/matthewcornell/arduino-relaxation-tool/blob/master/assembled-board.jpg).

Here is an example of the individual projects:

* Reading a pot: [Reading a Potentiometer (analog input)](https://www.arduino.cc/en/Tutorial/Potentiometer)
* Driving a piezo motor: [Figure 8-8 of the Arduino Cookbook](https://books.google.com/books?id=raHyKejOBF4C&pg=PA276&lpg=PA276&dq=figure+8-8+connecting+a+vibration+motor&source=bl&ots=gmm0_Rgz7K&sig=LKvfqXUdqfFy6ZoNYdsy1oS8n7M&hl=en&sa=X&ved=0CB8Q6AEwAGoVChMI38mBqpnmxwIVwj4-Ch15Hgby#v=onepage&q=figure%208-8%20connecting%20a%20vibration%20motor&f=false)

Parts:

* 2 x 1K Ohm resistors
* 2 x 2N2222 transistors
* 2 x 1N4001 diodes
* 2 x 0.1uF capacitors
* 2 x piezo motors, e.g., [Micro Vibrating Motor Cell Phone Beam Bristlebot Robot 6x10mm](http://www.ebay.com/itm/10X-Micro-Vibrating-Motor-Cell-Phone-Beam-Bristlebot-Robot-6x10mm-Arduino-PI-USA-/161237537955?hash=item258a8194a3)
* 2 x 33 Ohm resistors
* 2 x 10K Ohm circuit board pots

