#include "DHT.h"

// Define the ESP32 pin connected to the DHT Data pin
#define DHTPIN 4     

// Define the type of sensor you are using
#define DHTTYPE DHT22  // Change to DHT22 if you have the white sensor

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("\n--- DHT ISOLATION TEST ---");

  // Start the sensor
  dht.begin();
}

void loop() {
  // Wait 2 seconds between measurements (DHT sensors are slow!)
  delay(2000);

  // Read humidity
  float humidity = dht.readHumidity();
  
  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor! Check your wiring.");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.println("===========================");
  Serial.print("Humidity:    ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.println("===========================\n");
}