#include "BluetoothSerial.h"
BluetoothSerial BT; // Objeto Bluetooth

const int D2 = 2;
const int D4 = 4;
const int D16 = 16;
const int D17 = 17;

int incoming = 0;

void setup() {
  Serial.begin(9600); // Inicialización de la conexión en serie para la depuración
  BT.begin("Carro robot 1.0"); // Nombre de su dispositivo Bluetooth y en modo esclavo
  Serial.println("El dispositivo Bluetooth está listo para emparejarse");
  pinMode(D2, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D16, OUTPUT);
  pinMode(D17, OUTPUT);
}

void loop() {
  if (BT.available()) // Compruebe si recibimos algo de Bluetooth
  {
    incoming = BT.read(); // Lee lo que recibimos
    switch (incoming){
      case 70:
        adelante();
        break;
      case 66:
        atras();
        break;
      case 76:
        izquierda();
        break;
      case 82:
        derecha();
        break;
      case 48:
        frenar();
        break;
    
    }
  
  }
  delay(20);
}

void izquierda(){
  Serial.println("izquierda");
  digitalWrite(D16, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D17, LOW);
}
void derecha(){
  Serial.println("derecha");
  digitalWrite(D4, HIGH);
  digitalWrite(D16, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D17, LOW);
}
void adelante(){
  digitalWrite(D4, HIGH);
  digitalWrite(D16, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D17, LOW);
  Serial.println("adelante");
}
void atras(){
  digitalWrite(D4, LOW);
  digitalWrite(D16, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D17, HIGH);
  Serial.println("atras");
}

void frenar(){
Serial.println("frenar");
  digitalWrite(D4, LOW);
  digitalWrite(D16, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D17, LOW);
}
