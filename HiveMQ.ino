#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// WiFi
const char* ssid = "Airtel_Airtel-Pumo";
const char* password = "Mustang5.0";

// HiveMQ Cloud
const char* mqtt_server =
"c1dba197a34a494595755cbc080bd98d.s1.eu.hivemq.cloud";

const int mqtt_port = 8883;

const char* mqtt_user = "madhura";
const char* mqtt_password = "Madhura28";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length)
{
  String msg = "";

  for (int i = 0; i < length; i++)
  {
    msg += (char)payload[i];
  }

  Serial.print("Message Received: ");
  Serial.println(msg);

  if (msg == "ON")
  {
    digitalWrite(2, HIGH);
  }

  if (msg == "OFF")
  {
    digitalWrite(2, LOW);
  }
}

void setup_wifi()
{
  WiFi.begin(ssid, password);

  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Connecting MQTT...");

    if (client.connect(
          "ESP32Client",
          mqtt_user,
          mqtt_password))
    {
      Serial.println("Connected");

      client.subscribe("esp32/led");

      client.publish(
        "esp32/status",
        "ESP32 Connected");
    }
    else
    {
      Serial.print("Failed rc=");
      Serial.println(client.state());

      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(2, OUTPUT);

  dht.begin();

  setup_wifi();

  espClient.setInsecure();

  client.setServer(
    mqtt_server,
    mqtt_port);

  client.setCallback(callback);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }

  client.loop();

  float temp = dht.readTemperature();

  if (!isnan(temp))
  {
    char tempString[10];

    dtostrf(
      temp,
      1,
      2,
      tempString);

    client.publish(
      "esp32/temperature",
      tempString);

    Serial.print(
      "Published: ");

    Serial.println(
      tempString);
  }

  delay(5000);
}