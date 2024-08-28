int led_rojo = 5;
int led_amarillo = 4;
int led_verde = 3;
int pulsador = 12;

char data;
int modoOperacion = 0;

int veces_pulsadas = 0;
int aux = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(pulsador, INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    if (data == 'p') {
      modoOperacion = 1;
    }
    else if(data == 'a') {
      modoOperacion = 2;
    }
  }

  if (modoOperacion == 1) {
    Serial.println("Modo normal ON");

    Serial.println("LedRojo ON");
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_verde, LOW);
    delay(5000);
    Serial.println("LedRojo OFF");

    Serial.println("LedVerde ON");
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, HIGH);
    delay(3000);
    Serial.println("LedVerde OFF");

    Serial.println("LedAmarillo ON");
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, HIGH);
    delay(1000);
    Serial.println("LedAmarillo OFF");

    digitalWrite(led_amarillo, LOW);
  } 
  else if (modoOperacion == 2) {
    Serial.println("Modo mantenimiento ON");

    Serial.println("LedRojo ON");
    Serial.println("LedVerde ON");
    Serial.println("LedAmarillo ON");
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_verde, HIGH);
    delay(500);

    Serial.println("LedRojo OFF");
    Serial.println("LedVerde OFF");
    Serial.println("LedAmarillo OFF");
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_verde, LOW);
    delay(500);
  } 

  delay(50);
}
