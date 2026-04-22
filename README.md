A real-time air quality monitoring node using the ESP32 and the Plantower PMS5003 laser scattering particulate matter sensor. This project measures PM1.0, PM2.5, and PM10 concentrations.

**Features**
Real-time laser-based particle sensing.
High-speed 115200 baud serial communication for debugging.
Optimized data packet synchronization to prevent "buffer lag."
Hardware-level troubleshooting for custom sensor cables.

**Hardware Components**
Microcontroller: ESP32 (DOIT DevKit V1 or similar).
Sensor: Plantower PMS5003.
Connection: 5V Power (VIN), Ground, and UART Serial (RX2/TX2).

**Wiring Diagram**
Warning: Ribbon cable colors on PMS5003 sensors are often non-standard. Always verify with a multimeter before powering.

**Software Installation**
Install the ESP32 Board Manager in the Arduino IDE.
Select DOIT ESP32 DEVKIT V1 as your board.
If the upload fails with a "Write Timeout," hold the BOOT button on the ESP32 until the upload begins.
Open the Serial Monitor at 115200 baud.

**The Code**
The provided script uses Serial2 on the ESP32 to communicate with the sensor at 9600 baud. It features a robust search algorithm that scans for the 0x42 and 0x4D header bytes to ensure data alignment.

**Troubleshooting Tips (Lessons Learned)**
Silent Fan: The fan is extremely quiet. If you aren't sure it's working, place your ear against the blue casing; you should hear a high-pitched whir.

No Data / Blank Screen: Swap the TX and RX wires. If the "mouth" of the sensor is connected to the "mouth" of the ESP32, no data will be received.

Garbage Characters: Ensure your Serial Monitor is set to 115200 baud, but your Serial2.begin is set to 9600 baud.

License
This project is open-source and available under the MIT License.
