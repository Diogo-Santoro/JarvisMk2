const int pinPump1 = 2;
const int pinPump2 = 3;
const int pinPump3 = 4;
const int pinPump4 = 5;
//const int pinPump5 = 6;


void clearSerialInput() {
  while (Serial.available() > 0) {
    Serial.read(); // Lê e descarta qualquer caractere disponível na serial.
  }
}

void stopAllPumps(){

  digitalWrite(pinPump1, HIGH);
  digitalWrite(pinPump2, HIGH);
  digitalWrite(pinPump3, HIGH);
  digitalWrite(pinPump4, HIGH);
  Serial.println("- #LOG: Todas as bombas foram paradas");

}


void setup() {

  Serial.begin(9600);

  pinMode(pinPump1, OUTPUT);
  pinMode(pinPump2, OUTPUT);
  pinMode(pinPump3, OUTPUT);
  pinMode(pinPump4, OUTPUT);

  Serial.println("Script para teste - Build .._\n");
  Serial.println("+===== Jarvis Mk2 =====+\n");

  stopAllPumps();

}

void loop(){

  bool ON = false;
  bool OFF = true;
  
  float running_time = 1000;

  Serial.println("\nTest Menu - (Main)\n");
  Serial.println("Escolha uma das opções abaixo: \n");
  Serial.println("1- Bomba 1\n2- Bomba 2\n3- Bomba 3\n4- Bomba 4\n5- Bomba 5\n0- Sair de tudo");
  Serial.print("Opção: ");

  while (Serial.available() == 0) {
    // Aguarda a entrada do usuário.
  }//- WHILE DA SERIAL

  int opt_pump = Serial.parseInt();

  if(opt_pump == 0){
    Serial.println("Encerrando\n");
    while(true){
      //-
    } //- WHILE de ENCERRAMENTO
  }else if(opt_pump >0 && opt_pump <= 4){

    switch(opt_pump){
      
      case 1:
      clearSerialInput();
        Serial.println("- #LOG: Bomba selecionada: Bomba 1\n\n");

        Serial.println(" - Menu Bomba 1 - (Test Menu) - \n");
        Serial.println(" Selecione uma das Bomba 1: \n");
        Serial.println("1- Ligar Bomba 1\n2- Desligar Bomba 2\n3- Configurar Bomba 1\n0- Sair");

        while (Serial.available() == 0) {
          // Aguarda a entrada do usuário.
        }//- WHILE DA SERIAL

        int opt_menu_pump = Serial.parseInt();

        if(opt_menu_pump == 0){
          Serial.println("Encerrando\n");
          while(true){
             //-
           } //- WHILE de ENCERRAMENTO
        }else if(opt_menu_pump > 0 && opt_menu_pump <= 4){
          switch(opt_menu_pump){

            case 1:
              Serial.print("- #LOG: RUNNING PUMP 1");
              digitalWrite(pinPump1, ON);
              delay(running_time);
              digitalWrite(pinPump1, OFF);
              break;
            case 2:
              Serial.print("- #LOG: STOPING PUMP 1");
              digitalWrite(pinPump1, OFF);
              break;
            case 3:
              Serial.println("+====================================+");
              Serial.print("\n- #LOG: CONFIG MENU - PUMP 1\n\n");
              Serial.println(" - Config Menu PUMP 1 - (Test Menu) - ");
              Serial.println(" Selecione uma opção: ");
              Serial.print("1- Definir 'MAIN_RUN_TIME' da Bomba 1: ");
              
              break;
            case 0:
              while(true){
                //-
              }
              break;
            default:
              Serial.print("- #LOG: Opção não reconhecida: "); Serial.println(opt_menu_pump);
              break;
          }
        }

        break;
      case 2:
        Serial.println("- #LOG: Bomba selecionada: Bomba 2");
        break;
      case 3:
        Serial.println("- #LOG: Bomba selecionada: Bomba 3");
        break;
      case 4:
        Serial.println("- #LOG: Bomba selecionada: Bomba 4");
        break;

    }

  }

}//- Fim do LOOP
