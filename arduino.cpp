//D4,D5 & D19
//3V3, GND
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid ='(nama WIfI)';
const char* password ='(password)';

const int espLed = 2;
const int letpin1 = 4;
const int letpin2 = 5;
const int letpin3 = 19;

bool dapurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;

void setup(){
    Serial.begin(115200);
  pinMode(espLed, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  WiFi.begin(ssid,password);
  Serial.print("connecting to wifi.....")

  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(espWrite, LOW);
    delay(1000);
    serial.print(".")
  }
  digitalWrite(espLed, HIGH);
  Serial.println("");
  Serial.Println("connected to wifi network!");
  Serial.Println(WiFi.localIP)

  server.on("/dapur", HTTP_GET, getDapurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET,getMakanLed);

  server.on("/dapur", HTTP_POST, setDapurLed);
  server.on("/tamu", HTTP_POST, setTamuLed);
  server.on("/makan", HTTP_POST,setMakanLed);

  server.begin();
  Serial.println("server started....")
}
void loop(){
    server.handleClient();
}
void setDapurLed(){
    dapurLedState = !dapurLedState;
    // true-> high (nyala)
    // false-> low (mati)
    digitalWrite(ledPin1, dapurLedState ? HIGH : LOW);
    server.sendHeader("acces-Controll-Allow-Origin", "*");
    server.send(200, "tect/plain", dapurLedState ? "ON" : "OFF")
}
void setTamuLed(){
    tamuLedState = !tamuLedState;
    digitalWrite(ledPin2, tamuLedState ? HIGH : LOW);
    server.sendHeader("acces-Controll-Allow-Origin", "*");
    server.send(200, "tect/plain", tamuLedState ? "ON" : "OFF")
}
void setMakanLed(){
    makanLedState = !makanLedState;
    digitalWrite(ledPin3, maknaLedState ? HIGH : LOW);
    server.sendHeader("acces-Controll-Allow-Origin", "*");
    server.send(200, "tect/plain", makanLedState ? "ON" : "OFF")
}
void getDapurLed(){
    server.sendHeader("acces-Controll-Allow-Origin", "*");
    server.send(200, "tect/plain", dapurLedState ? "ON" : "OFF")
}
void getTamuLed(){
    server.sendHeader("acces-Controll-Allow-Origin", "*");
    server.send(200, "tect/plain", tamuLedState ? "ON" : "OFF")
}
void getMakanLed(){
    server.sendHeader("acces-Controll-Allow-Origin", "*");
    server.send(200, "tect/plain", makanLedState ? "ON" : "OFF")
}