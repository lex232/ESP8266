#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#import "index.h"

/* Put your SSID & Password */
const char* ssid = "iPhone128";  // Enter SSID here
const char* password = "1234567890";  //Enter Password here

//const char* ssid = "tfsi";  // Enter SSID here
//const char* password = "peugeot406";  //Enter Password here
char value = 87;

IPAddress ip(192, 168, 2, 177);
IPAddress gateway(192, 168, 2, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  delay(100);
  WiFi.mode(WIFI_STA);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.begin();
  server.on("/", handleRoot);
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}
