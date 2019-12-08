#include <WiFiClientSecure.h> 
#include "config.h"

void wifiConnect(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) { delay(100); }
}

void sendLineNotify(const char* host, const char* token, char* message) {
  WiFiClientSecure client;  
  String query = String("message=") + String(message);
  String request = String("") +
               "POST /api/notify HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Authorization: Bearer " + token + "\r\n" +
               "Content-Length: " + String(query.length()) +  "\r\n" + 
               "Content-Type: application/x-www-form-urlencoded\r\n\r\n" +
                query + "\r\n";

  client.connect(host, 443);
  client.print(request);
}

void setup() {
  Serial.begin(9600);
  wifiConnect(ssid, password);
}

void loop() {
  sendLineNotify(host, token, "send message");
  delay(60000);
}
