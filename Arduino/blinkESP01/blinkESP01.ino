#define LED_PIN 1
#define BOTON 2   //GPIO 2
int a;

void setup() {
  pinMode(LED_PIN, OUTPUT);     // Initialize the LED_PIN pin as an output
  pinMode(BOTON,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  a = digitalRead(BOTON);
  if(a == LOW) {
    //Serial.println("Botón pulsado");
    digitalWrite(LED_PIN,LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    }
  digitalWrite(LED_PIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(30);                      // Wait for a second
  digitalWrite(LED_PIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(30);                      // Wait for two seconds (to demonstrate the active low LED)
}
