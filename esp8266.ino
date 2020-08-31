#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* URL = "http://quan.suning.com/getSysTime.do";
const char* ssid = "MERCURY_EA80";
const char* password = "mercury223223";


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void loop() {
  HTTPClient httpClient;
  httpClient.begin(URL);
  if (WiFi.status() == WL_CONNECTED) {
    int httpCode = httpClient.GET();  
    if (httpCode == HTTP_CODE_OK) {
      String responsePayload = httpClient.getString();
      const size_t capacity =JSON_OBJECT_SIZE(2) + 90;
      DynamicJsonDocument doc(90);
      String json = responsePayload;
      deserializeJson(doc, json);
      String Time = doc["sysTime2"].as<String>();
      Serial.println(Time);
    }
  }
  httpClient.end();
  delay(1000);

}
