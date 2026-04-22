void setup() {
  Serial.begin(115200);
  // Force pins 16 and 17
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  delay(1000);
  Serial.println("\n--- SEARCHING FOR SENSOR DATA PACKET ---");
}

void loop() {
  if (Serial2.available() > 0) {
    uint8_t c = Serial2.read();
    
    // Look for the start of the 32-byte packet
    if (c == 0x42) { 
      // Wait a tiny bit for the rest of the packet to arrive
      delay(100); 
      
      if (Serial2.available() >= 31) {
        uint8_t secondByte = Serial2.read();
        if (secondByte == 0x4D) {
          
          uint8_t buffer[30];
          Serial2.readBytes(buffer, 30);

          // Standard PM values (Environmental)
          int pm1 = (buffer[8] << 8) | buffer[9];
          int pm25 = (buffer[10] << 8) | buffer[11];
          int pm10 = (buffer[12] << 8) | buffer[13];

          Serial.println("\n==============================");
          Serial.println("   AIR QUALITY SUCCESS!       ");
          Serial.print("   PM 1.0 : "); Serial.print(pm1); Serial.println(" ug/m3");
          Serial.print("   PM 2.5 : "); Serial.print(pm25); Serial.println(" ug/m3");
          Serial.print("   PM 10.0: "); Serial.print(pm10); Serial.println(" ug/m3");
          Serial.println("==============================");
        }
      }
    }
  }
}