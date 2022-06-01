# Desk-Buddy

DeskBuddyDisplay.ino

The program connects a lcd to arduino via i2c. The lcd can be controlled via three buttons. A dht sensor registers the ambiental temperature and humidity.
When pressing the button connected to digital pin 7, the lcd displays the humidity detected by the sensor along with a miniature pixelated drawing which changes based on the
level of humidity detected. The button connected to digital pin 5 works a lot like the former button, except it displays the temperature.
When pressing the button connected to digital pin 4, a series of predefined messages is unlocked and one of them will display on the lcd. Messaged regarding the current
temperature and humidity can also be displayed at random, therefore emulating some sort of "thinking process" of the robot.

DeskBuddyMP3Player.ino

The program helps connect 3 LEDs, a button, a sound sensor and a DFPlayerMini to an arduino. Every button press plays one of the songs loaded in the MicroSD card of the
player. The map function is used to convert the value read by the sound sensor into a value ranging from 0 to 255. The value is then used to light up the LEDs so that the
music's beat is matched by a corresponding light show.

DeskBuddyMotors.ino

The purpose of the program is to coordinate the 4 Gear Motors so that the robot avoids obstacles via an ultrasonic sensor and avoids falling off a surface via an IR sensor.
The robot begins by checking if the distance between him and the next obstacle is higher than a predefined value or if the IR sensor detects a lower height. If so, the servo
allows the ultrasonic sensor to look both left and right so that he may choose the best direction in which to turn. If no obstacles are detected, the robot may move forward.
