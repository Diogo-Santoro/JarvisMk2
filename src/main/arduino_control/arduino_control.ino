#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10, 11); // Pinos 10 (RX) e 11 (TX) para a comunicação Bluetooth.

int pump1Pin = 2; // Define o pino digital 2 como o pino de controle da bomba 1.
int pump2Pin = 3; // Define o pino digital 3 como o pino de controle da bomba 2.
int pump3Pin = 4; // Define o pino digital 4 como o pino de controle da bomba 3.
int pump4Pin = 5; // Define o pino digital 5 como o pino de controle da bomba 4.

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial padrão a uma taxa de transmissão de 9600 baud.
  bluetoothSerial.begin(9600);  // Inicializa a comunicação serial Bluetooth a 9600 baud.
  pinMode(pump1Pin, OUTPUT);  // Configura o pino da bomba 1 como saída.
  pinMode(pump2Pin, OUTPUT);  // Configura o pino da bomba 2 como saída.
  pinMode(pump3Pin, OUTPUT);  // Configura o pino da bomba 3 como saída.
  pinMode(pump4Pin, OUTPUT);  // Configura o pino da bomba 4 como saída.
  digitalWrite(pump1Pin, LOW);  // Desliga a bomba 1 no início.
  digitalWrite(pump2Pin, LOW);  // Desliga a bomba 2 no início.
  digitalWrite(pump3Pin, LOW);  // Desliga a bomba 3 no início.
  digitalWrite(pump4Pin, LOW);  // Desliga a bomba 4 no início.
}

void testPump1() {
  digitalWrite(pump1Pin, HIGH);
  bluetoothSerial.println("Bomba 1 ligada");  // Envia uma mensagem via Bluetooth
  Serial.println("Comando recebido: 1");  // Imprime um log serial
}

void testPump2() {
  digitalWrite(pump2Pin, HIGH);
  bluetoothSerial.println("Bomba 2 ligada");  // Envia uma mensagem via Bluetooth
  Serial.println("Comando recebido: 2");  // Imprime um log serial
}

void testPump3() {
  digitalWrite(pump3Pin, HIGH);
  bluetoothSerial.println("Bomba 3 ligada");  // Envia uma mensagem via Bluetooth
  Serial.println("Comando recebido: 3");  // Imprime um log serial
}

void testPump4() {
  digitalWrite(pump4Pin, HIGH);
  bluetoothSerial.println("Bomba 4 ligada");  // Envia uma mensagem via Bluetooth
  Serial.println("Comando recebido: 4");  // Imprime um log serial
}

void loop() {
  if (bluetoothSerial.available()) {  // Verifica se há dados disponíveis na comunicação Bluetooth.
    char command = bluetoothSerial.read();  // Lê um caractere (comando) da comunicação Bluetooth.
    
    switch (command) {  // Inicia uma estrutura de controle de switch com base no comando lido.
      case '1':  // Se o comando for '1'.
        testPump1();  // Chama a função para ligar a bomba 1.
        break;  // Sai do switch.
      case '2':  // Se o comando for '2'.
        testPump2();  // Chama a função para ligar a bomba 2.
        break;  // Sai do switch.
      case '3':  // Se o comando for '3'.
        testPump3();  // Chama a função para ligar a bomba 3.
        break;  // Sai do switch.
      case '4':  // Se o comando for '4'.
        testPump4();  // Chama a função para ligar a bomba 4.
        break;  // Sai do switch.
      case '0':  // Se o comando for '0'.
        digitalWrite(pump1Pin, LOW);  // Desliga a bomba 1.
        digitalWrite(pump2Pin, LOW);  // Desliga a bomba 2.
        digitalWrite(pump3Pin, LOW);  // Desliga a bomba 3.
        digitalWrite(pump4Pin, LOW);  // Desliga a bomba 4.
        bluetoothSerial.println("Todas as bombas desligadas");  // Envia uma mensagem via Bluetooth
        Serial.println("Comando recebido: 0");  // Imprime um log serial
        break;  // Sai do switch.
      default:  // Se o comando não for reconhecido.
        Serial.println("Comando recebido inválido");  // Imprime um log serial
        break;  // Sai do switch.
    }
  }
}
