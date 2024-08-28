int ledRojo= 5;
int led_amarillo = 4;
int led_verde = 3;
int pulsador = 12;

char data;

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

  if (Serial.available()>0) {
    data = Serial.read();
    if (data == 'p') {
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_verde, LOW);
    delay(5000);
    
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, HIGH);
    delay(3000);
    
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, HIGH);
    delay(1000);
    
    digitalWrite(led_amarillo, LOW);
    Serial.println("Modo normal ON");
    }
    else if (data == 'a'){
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_verde, HIGH);
    delay(500);
    
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_verde, LOW);
    delay(500);
    Serial.println("Modo mantenimiento ON");
    } else {
      Serial.print("Dato recibido:");
      Serial.print(data);
    }
  }

  delay(50);
}
