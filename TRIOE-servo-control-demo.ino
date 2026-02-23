#include <ESP32Servo.h>

#define SERVO_PIN 4
Servo myServo;

int mode = 0;
unsigned long lastModeSwitch = 0;
const unsigned long modeDuration = 10000; // Switch mode every 10 seconds (10000ms)

void setup() {
    Serial.begin(115200);
    myServo.setPeriodHertz(50);           
    myServo.attach(SERVO_PIN, 500, 2400); 
    
    Serial.println("--- ESP32 Servo Multi-Mode System Initialized ---");
}

void loop() {
    // Automatic Mode Switcher
    if (millis() - lastModeSwitch > modeDuration) {
        mode = (mode + 1) % 5; // Cycle through 5 modes (0 to 4)
        lastModeSwitch = millis();
        
        Serial.println("\n*********************************");
        Serial.print("SWITCHING TO MODE: ");
        printModeName(mode);
        Serial.println("*********************************");
    }

    // Execute current mode
    switch (mode) {
        case 0: sweepMode();   break;
        case 1: stepMode();    break;
        case 2: jitterMode();  break;
        case 3: fastSnapMode(); break; // New: Rapid back-and-forth
        case 4: slowCreepMode();break; // New: Very slow movement
    }
}

// Helper function for Serial identification
void printModeName(int m) {
    switch(m) {
        case 0: Serial.println("0 (Smooth Sweep)"); break;
        case 1: Serial.println("1 (Precision Steps)"); break;
        case 2: Serial.println("2 (Random Jitter)"); break;
        case 3: Serial.println("3 (Fast Snap)"); break;
        case 4: Serial.println("4 (Slow Creep)"); break;
    }
}

// MODE 0: Smooth Sweep
void sweepMode() {
    Serial.println("Sweeping 0 -> 180");
    for (int pos = 0; pos <= 180; pos += 1) {
        myServo.write(pos);
        delay(15);
    }
    Serial.println("Sweeping 180 -> 0");
    for (int pos = 180; pos >= 0; pos -= 1) {
        myServo.write(pos);
        delay(15);
    }
}

// MODE 1: Precision Steps
void stepMode() {
    int positions[] = {0, 45, 90, 135, 180};
    for(int i=0; i<5; i++) {
        Serial.print("Stepping to: "); Serial.println(positions[i]);
        myServo.write(positions[i]);
        delay(1000);
    }
}

// MODE 2: Random Jitter
void jitterMode() {
    int randomPos = random(0, 181);
    Serial.print("Jittering to: "); Serial.println(randomPos);
    myServo.write(randomPos);
    delay(random(100, 500)); 
}

// MODE 3: Fast Snap (Action/Reactive style)
void fastSnapMode() {
    Serial.println("Snapping: 0");
    myServo.write(0);
    delay(300);
    Serial.println("Snapping: 180");
    myServo.write(180);
    delay(300);
}

// MODE 4: Slow Creep (Stalking/Stealth style)
void slowCreepMode() {
    Serial.println("Creeping slow...");
    for (int pos = 0; pos <= 180; pos++) {
        myServo.write(pos);
        delay(100); // Very slow movement
        if (pos % 45 == 0) { Serial.print("Current Pos: "); Serial.println(pos); }
    }
}