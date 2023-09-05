
/*// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}*/

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);  // Pinos RX (10) e TX (11) para o módulo Bluetooth
int sensorPresencaPin = 2;        // Pino onde o sensor de presença está conectado

int PINO_BOMBA_1 = 3;  // Substitua pelo pino correto para a bomba 1
int PINO_BOMBA_2 = 4;  // Substitua pelo pino correto para a bomba 2
int PINO_BOMBA_3 = 5;  // Substitua pelo pino correto para a bomba 3
int PINO_BOMBA_4 = 6;  // Substitua pelo pino correto para a bomba 4

bool enviarDados = true;   // Sinaliza quando o Arduino deve enviar dados

void setup() {
  pinMode(sensorPresencaPin, INPUT);
  pinMode(PINO_BOMBA_1, OUTPUT);
  pinMode(PINO_BOMBA_2, OUTPUT);
  pinMode(PINO_BOMBA_3, OUTPUT);
  pinMode(PINO_BOMBA_4, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (enviarDados) {
    int presenca = digitalRead(sensorPresencaPin); // Lê o valor do sensor de presença

    // Envie os dados via Bluetooth para o aplicativo Python
    bluetooth.print("P:" + String(presenca)); // Envie a detecção de presença como uma string com um prefixo
    bluetooth.println(); // Envie uma nova linha para indicar o fim dos dados

    enviarDados = false; // Aguarde a próxima vez para enviar dados
  }

  // Verifique se há comandos disponíveis no monitor serial
  if (Serial.available()) {
    char command = Serial.read();

    // Execute ação com base no comando recebido
    switch (command) {
      case '1':
        // Ative a bomba 1
        digitalWrite(PINO_BOMBA_1, HIGH);
        break;
      case '2':
        // Ative a bomba 2
        digitalWrite(PINO_BOMBA_2, HIGH);
        break;
      case '3':
        // Ative a bomba 3
        digitalWrite(PINO_BOMBA_3, HIGH);
        break;
      case '4':
        // Ative a bomba 4
        digitalWrite(PINO_BOMBA_4, HIGH);
        break;
      case '0':
        // Desative todas as bombas
        digitalWrite(PINO_BOMBA_1, LOW);
        digitalWrite(PINO_BOMBA_2, LOW);
        digitalWrite(PINO_BOMBA_3, LOW);
        digitalWrite(PINO_BOMBA_4, LOW);
        break;
    }
  }
}
