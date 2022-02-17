#include <ESP8266WiFi.h>
#define STASSID "INFINITUMXXXX"
#define STAPSK  "0123456789"
#define LED_PIN 1 //TX Pin
#define BOTON 2   //GPIO 2
const char* ssid = STASSID;
const char* password = STAPSK;
String req, val, last, current;
int n = 0;
int a;
IPAddress ip(192,168,1,200);     
IPAddress gateway(192,168,1,1);   
IPAddress subnet(255,255,255,0);
WiFiServer server(80);

void setup() {
  //Serial.begin(115200);
  digitalWrite(LED_PIN, HIGH);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BOTON,INPUT);
  //Serial.print(F("Connecting to "));
  //Serial.println(ssid);
  WiFi.mode(WIFI_STA);          // WiFi modo estación
  wifi_set_sleep_type(MODEM_SLEEP_T);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(F("."));
  }
  //Serial.println(F("WiFi connected"));
  server.begin();
  //Serial.println(F("Server started"));
  //Serial.println(WiFi.localIP());
}

void loop() {
  a = digitalRead(BOTON);
  if(a == LOW) {
    //Serial.println("Botón pulsado");
    digitalWrite(LED_PIN,LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    }
  WiFiClient client = server.available();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println(val);
  if (!client) {return;}
  client.setTimeout(1000);
  req = client.readStringUntil('\r');
  if       (req.indexOf("/0") != -1 )  { val = "0"; }
  else if  (req.indexOf("/1") != -1)   { val = "1"; }
  
  //Serial.println(val);
  last = current;  current = val;
  if(current != last) { 
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    }
}
