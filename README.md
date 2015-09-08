# arduino-relaxation-tool
This project contains the code and circuit diagram to create a simple vibration-based relaxation tool using an [Arduino](https://www.arduino.cc/).
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


# Parts
* 2 x 1K Ohm resistors
* 2 x 2N2222 transistors
* 2 x 1N4001 diodes
* 2 x 0.1uF capacitors
* 2 x piezo motors, e.g., [Micro Vibrating Motor Cell Phone Beam Bristlebot Robot 6x10mm](http://www.ebay.com/itm/10X-Micro-Vibrating-Motor-Cell-Phone-Beam-Bristlebot-Robot-6x10mm-Arduino-PI-USA-/161237537955?hash=item258a8194a3)
* 2 x 33 Ohm resistors
* 2 x 10K Ohm circuit board pots


# Assembly
I used a basic Arduino breadboard - it was pretty straighforward. I didn't have any 33 Ohm resistors so I had to use
3 x 10 Ohm ones in series. For the motors I simply applied some heat shrink tubing for something to hold onto. I
looked into more durable cases (I tried ping pong balls), but this worked OK for the prototype. See the pic
[here](https://github.com/matthewcornell/arduino-relaxation-tool/blob/master/motor-closeup.JPG).


# Code
The code manages four pins - two analog in ones for reading the pots, and two digital out ones for controlling the motors. The fifth pin is the built in LED digital out one that I pulse for effect. The pots are read by `adjustPeriodAndDurationBasedOnPots()` and saved into two variables: `vibePeriod` (how often the motor vibrates in ms: a range ~ [100 ms, 2000 ms]) and `vibeDuration` (how long the motor vibrates, in the same time range). The last variable is `isCycleLedOn`, which alternates between 0 and 1 with each cycle. After [setup()](https://www.arduino.cc/en/Reference/Setup) initializes the pins, The standard Arduino [loop()](https://www.arduino.cc/en/Reference/Loop) function just reads the pots (which sets the two control variables), cycles the first motor, and repeats for the second one. `cycleMotor()` turns on the motor, cycles the LED, waits the appropriate duration, then repeats to turn the motor off. Finally, `adjustPeriodAndDurationBasedOnPots()` reads the analog value from each pot (a value between 0 and 1023) and scales it to a range between ~100ms to 2000ms, which seemed to work pretty well. (Any faster was irritating, and any slower would have been boring :-)

