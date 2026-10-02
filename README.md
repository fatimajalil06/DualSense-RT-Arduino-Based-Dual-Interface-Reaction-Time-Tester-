
# DualSense RT: Arduino-Based Dual-Interface Reaction Time Tester ⚡

Engineered an embedded C++ reaction time tester built with Arduino Uno, featuring TTP223 capacitive touch sensing, debounced push-button inputs, anti-cheating delay logic, millisecond-accurate reflex measurement and measures human visual reflex response latency in milliseconds.


## 🛠️ Features
- **Dual-Interface Logic:** Accepts triggers via TTP223 Capacitive Touch Sensor (Active HIGH) and Push Button (Active LOW).
- **Anti-Cheating Guard:** Detects early/false triggers during the random delay phase and applies a penalty reset.
- **Randomized Stimulus Delay:** Prevents muscle-memory prediction by generating dynamic delays between 1.5s to 4.0s.
- **Millisecond Precision:** Calculates reaction speed using microsecond/millisecond hardware timers (`millis()`).

## 🔌 Hardware Setup & Components
- 1x Arduino Uno R3
- 1x TTP223 Capacitive Touch Sensor Module (Pin 2)
- 1x Tactile Push Button (Pin 3, `INPUT_PULLUP`)
- 3x LEDs (Red - Pin 8, Green - Pin 9, Yellow - Pin 10)
- 3x 220Ω Resistors
- 1x Breadboard & Jumper Wires

## 📊 System Flow
1. **Standby State:** Yellow LED turns ON; waits for user initiation.
2. **Warning State:** Yellow turns OFF, Red LED turns ON. A random delay (1.5s–4s) initiates.
3. **Stimulus State:** Red turns OFF, Green LED turns ON instantly. Timer starts.
4. **Measurement:** Touch or button press stops timer and outputs millisecond reaction time over Serial (9600 Baud).

## 📄 Circuit Schematic
![Circuit Diagram](Circuit_Diagram.png)

## 🚀 How to Run
1. Connect hardware according to the schematic.
2. Open `DualSense_RT.ino` in Arduino IDE.
3. Select **Arduino Uno** and your COM Port, then click **Upload**.
4. Open **Serial Monitor** at **9600 Baud Rate**.

## 🎯 Practical Applications & Use Cases

- **Sports Science & Athletic Training:** Evaluates athlete reaction speeds and motor-reflex efficiency for high-tempo sports.
- **Gaming & Esports Performance:** Benchmarks and tracks professional gamers' visual-to-tactile response latency.
- **Biomedical & Neuromuscular Research:** Serves as a low-cost quantitative tool to study human neuromuscular delay and cognitive processing speed.
- **Ergonomic & UX Testing:** Compares latency differences between traditional mechanical switches (push buttons) and capacitive touch interfaces[cite: 2].
- **Driver Fatigue & Alertness Monitoring:** Assesses reaction times to measure drowsiness or delayed motor responses in safety-critical environments.
