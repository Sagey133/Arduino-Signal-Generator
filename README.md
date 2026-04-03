# Arduino-Signal-Generator
A signal generator made using Arduino which can toggle between outputting a sine, triangle, or square wave via PWM. Can be routed through either a low-pass filter or a high-pass filter, and includes a potentiometer to control amplitude. Signal is read through an oscilloscope.

## Features:
- Three waveforms: sine, square, and triangle
- Toggle between waves with a button
- Adjustable frequency via potentiometer
- Low-pass and high-pass filter outputs

## Components:
- Arduino MEGA 2560 R3
- 12 jumper cables
- 3 2kΩ resistors
- 3 104pF capacitors
- Push button
- 10k potentiometer
- DSO152 Oscilloscope

## How to use:
1. Upload signal_generator.ino
2. Press button to cycle between sine, triangle, and square wave.
3. Turn potentiometer to adjust frequency.

## Known Limitations:
- Sine and triangle waves are approximations due to PWM limitations
- Higher frequencies can reduce wave quality

