# Mission-Unsleepable

Embedded Systems Project - November 2022

Collaborator: Maxence Bigot

Goal of the project: 
For our Embedded Systems course, we had to come up with a project using the DEEP Purple Complete Board, a PCB card designed by the ESEO. Maxence and I decided to create an alarm clock that will wake you up everytime. However, smooth waking up is not guaranteed.

Fonctioning:
When the alarm rings, you have to push the button on the hatch to stop it. Nevertheless, when your hand will be detected by the sensor the hatch will flip and you will not be able to stop the alarm. If you take away your hand, the hatch will rotate back to its original position and reveal you the button. The only way to stop the alarm is to have a hand on top of the alarm clock, and to push the button underneath the lid through the hole in the back.

Features:
- Video alarm
- Custom ringtone and video
- Navigation through menus and options with a joystick

Components:
- LCD Screen 3 inches ILI9341
- Servo Motor MG996R
- Ultrasonic Sensor HCSR04
- Button
- Joystick
- Speaker TMQ60500
- Audio Amplificator PAM8403
- mp3 Player HW311
- Nucleo STM32
- BluePill
- Deep Purple Complete Board
