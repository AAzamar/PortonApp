#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "jName.firebaseio.com"
#define FIREBASE_AUTH "JXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define WIFI_SSID "INFINITUMXXXX"
#define WIFI_PASSWORD "0123456789"
#define LED_PIN D2
String last, current;
int n = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    //Serial.print(".");
    delay(500);
  }
  // Serial.print("connected: ");
  // Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  // Firebase.setString("boton", "1");
  current = Firebase.getString("boton");
  last = current;
  Firebase.setString("ESP", "Listo_para_transmitir");
}

void loop() {
  last = current;
  current = Firebase.getString("boton");
  //Serial.print("current: ");Serial.println(current);
  //Firebase.setString("ESP2", String(n));
  if(current != last) {
    //Serial.println("The button is pressed");
    Firebase.setString("ESP", "La_señal_fue_activada");
    digitalWrite(LED_PIN, HIGH); delay(1000); digitalWrite(LED_PIN, LOW);
    Firebase.setString("ESP", "Listo_para_transmitir");
    }
  n=n+1;
}
