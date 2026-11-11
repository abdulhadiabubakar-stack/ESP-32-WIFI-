#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#define LedPin 4
#define LedPin2 8
#define LedPin3 16


const char *SSid = "Abdulhadi";
const char *password = "12345678";
WebServer server(80);

void handleRoot() {
  String html = R"rawliteral( 
  <html>
<head>
    <title>ESP32 WiFi LED</title>
</head>
<body>

    <div>
        <a href="/on">
            <button>ON</button>
        </a>

        <a href="/off">
            <button>OFF</button>
        </a>
    </div>

    <h2>
      <div>
        <a href="/on2">
            <button>ON</button>
        </a>

        <a href="/off2">
            <button>OFF</button>
        </a>
      </div>
    </h2>

 <h3>
      <div>
        <a href="/on3">
            <button>ON</button>
        </a>

        <a href="/off3">
            <button>OFF</button>
        </a>
      </div>
</h3>

</body>
</html>
  )rawliteral";
  server.send(200, "text/html", html);
}

void turnOn() {
    digitalWrite(LedPin, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
}

void turnOff() {
    digitalWrite(LedPin, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
}

void turnOn2() {
    digitalWrite(LedPin2, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
}

void turnOff2() {
    digitalWrite(LedPin2, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
}

void turnOn3() {
    digitalWrite(LedPin3, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);
}

void turnOff3() {
    digitalWrite(LedPin3, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
}

void setup() {
    pinMode(LedPin, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    WiFi.mode(WIFI_AP);                
    WiFi.softAP(SSid, password);
    server.on("/", handleRoot);        
    server.on("/on", turnOn);
    server.on("/off", turnOff);
    server.on("/on2", turnOn2);
    server.on("/off2", turnOff2);
    server.on("/on3", turnOn3);
    server.on("/off3", turnOff3);
    server.begin(); 
}

void loop() {
    server.handleClient();
}