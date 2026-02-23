# TRIOE_demo_servo-control
This is a multi-mode ESP32 servo control system designed for automated movement without external hardware like potentiometers. It features five distinct operational states—Smooth Sweep, Precision Steps, Random Jitter, Fast Snap, and Slow Creep—cycling every 10 seconds with real-time telemetry sent to the Serial Monitor at 115200 baud.
# TRIOE Servo Control Demo - Beginner's Guide

## What is This?

This is a simple Arduino project that demonstrates how to control servo motors. Servo motors are small motors that can rotate to specific angles, making them perfect for robotics, RC vehicles, and automated projects.

## What You'll Need

### Hardware
- **Arduino board** (Uno, Nano, Mega, etc.)
- **Servo motor** (SG90 or similar hobby servo)
- **USB cable** (to connect Arduino to computer)
- **Jumper wires** (at least 3)
- **Breadboard** (optional, makes wiring easier)
- **External power supply** (optional, for multiple or large servos)

### Software
- **Arduino IDE** - Download from [arduino.cc](https://www.arduino.cc/en/software)

## Wiring Instructions

Connect your servo to the Arduino:

| Servo Wire Color | Arduino Pin | Purpose |
|-----------------|-------------|---------|
| Brown/Black | GND | Ground |
| Red | 5V | Power |
| Orange/Yellow/White | Digital Pin (usually 9) | Signal |

**Important Notes:**
- Make sure the Arduino is NOT plugged in while wiring
- Double-check all connections before powering on
- For multiple servos, consider using an external 5V power supply

## Installation Steps

### Step 1: Install Arduino IDE
1. Download Arduino IDE from the official website
2. Install it on your computer
3. Open Arduino IDE

### Step 2: Load the Code
1. Open the `TRIOE-servo-control-demo.ino` file in Arduino IDE
2. The Servo library should be included automatically

### Step 3: Select Your Board
1. Go to **Tools** → **Board** → Select your Arduino model
2. Go to **Tools** → **Port** → Select the USB port your Arduino is connected to

### Step 4: Upload the Code
1. Click the **Upload** button (right arrow icon)
2. Wait for "Done uploading" message
3. Your servo should start moving!

## How to Use

Once uploaded, the servo will perform the programmed movements automatically. You can modify the code to:

- Change rotation angles
- Adjust movement speed
- Add pauses between movements
- Control servo with sensors or buttons

## Basic Code Understanding

Here are some key commands you'll see in servo control:

```cpp
#include <Servo.h>        // Include servo library
Servo myServo;            // Create servo object
myServo.attach(9);        // Connect to pin 9
myServo.write(90);        // Move to 90 degrees
delay(1000);              // Wait 1 second
```

**Servo Angles:**
- 0° = Fully left/down
- 90° = Center position
- 180° = Fully right/up

## Troubleshooting

### Servo Not Moving?
- Check all wire connections
- Verify the correct pin number in code
- Ensure Arduino has power
- Try a different servo (it might be broken)

### Servo Jittering?
- Use external power supply (Arduino USB might not provide enough current)
- Add a capacitor between power and ground

### Upload Errors?
- Check if correct board is selected
- Check if correct port is selected
- Close Serial Monitor if open
- Try a different USB cable

### Code Won't Compile?
- Make sure Servo library is installed
- Check for typos in the code

## Learn More

Want to expand your project? Try:

- **Add a button** - Control servo with button press
- **Add a potentiometer** - Control angle with a knob
- **Multiple servos** - Control several servos at once
- **Sensor control** - Make servo respond to distance or light

## Need Help?

- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Arduino Forum](https://forum.arduino.cc/)
- [Servo Library Reference](https://www.arduino.cc/reference/en/libraries/servo/)

## Safety Tips

**Always remember:**
- Disconnect power before wiring
- Don't reverse polarity (red to 5V, black to GND)
- Don't connect motors directly to Arduino pins (use proper power)
- Keep workspace dry and clean

---

**Happy Building!**

If you have questions or improvements, feel free to modify this code and experiment!
