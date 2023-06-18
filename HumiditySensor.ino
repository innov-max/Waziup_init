#include <DHT.h>

#define DHT_PIN 2   // The pin connected to the data line of the DHT sensor
#define DHT_TYPE DHT22   // Change to DHT11 if you're using a DHT11 sensor

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Delay for 2 seconds between readings

  float humidity = dht.readHumidity();    // Read humidity value from the sensor
  float temperature = dht.readTemperature();  // Read temperature value from the sensor in Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}
