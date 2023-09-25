#include <Arduino.h>

const int pinPump1 = 2;
const int pinPump2 = 3;
const int pinPump3 = 4;
const int pinPump4 = 5;
const int pinPump5 = 6;
const int pinSensor1 = 9;
const int pinSensor2 = 11;

String data_received = ""; // Variável global para armazenar dados recebidos

int pinPump00 = 7; // Exemplo de pino para a primeira bomba do Drink 1
int st_drink_flow_delay = 1000; // Exemplo de atraso entre as etapas do Drink 1

// Ingredientes
bool item_tonic_water = true;
bool item_orange_juice = true;
bool item_pineapple_juice = true;
bool item_strawberry_juice = true;
bool item_passionfruit_juice = true;

String drink1_id = "orange_juice";
String drink1_name = "Suco de Laranja c/Tônica";
String drink1_desc = "Drink baseado em suco de laranja e água tônica. Sem álcool.";

String item_tonic_water_name = "Água Tônica";
String item_orng_jc_name = "Suco de Laranja";
String item_pneapple_jc_name = "Suco de Abacaxi";
String item_strwbrry_jc_name = "Suco de Morango";
String item_pssnft_jc_name = "Suco de Maracujá";

int tonic_water_pumpId = 0;
int orng_jc_pumpId = 0;
int pneaple_jc_pumpId = 0;
int strwbrry_jc_pumpId = 0;
int pssnft_jc_pumpId = 0;



/*
int *pointer_tonic_water_pumpId = ;
int *pointer_orng_jc_pumpId = ;
int *pointer_pneaple_jc_pumpId = ;
int *pointer_strwbrry_jc_pumpId = ;
int *pointer_pssnft_jc_pumpId = ;
*/

void setup() {
  Serial.begin(9600);
  pinMode(pinPump1, OUTPUT);
  pinMode(pinPump2, OUTPUT);
  pinMode(pinPump3, OUTPUT);
  pinMode(pinPump4, OUTPUT);
  pinMode(pinPump5, OUTPUT);
  pinMode(pinSensor1, INPUT);
  pinMode(pinSensor2, INPUT);
}

void setup_item_name(){

  if(item_tonic_water && item_orange_juice && item_pineapple_juice && item_strawberry_juice && item_passionfruit_juice){
    
    /*
    int tonic_water_pumpId = 0;
    int orng_jc_pumpId = 0;
    int pneaple_jc_pumpId = 0;
    int strwbrry_jc_pumpId = 0;
    int pssnft_jc_pumpId = 0;
    */

    Serial.println("Selecione o elemento da Bomba 1: \n");
    Serial.println("\n-01 - " + item_tonic_water_name + "\n-02 - " + item_orng_jc_name + "\n-03 - " + item_pneapple_jc_name + "\n-04 - "  + item_strwbrry_jc_name + "\n-05 - " + item_pssnft_jc_name + "\n\n");
    serial_reader();

    String pump1Chk_state;
    pump1Chk_state += data_received;

     switch(pump1Chk_state){

      case '1' || '01':
        tonic_water_pumpId = pinPump1;
        Serial.println("Bomba 1 setada como: " + item_tonic_water_name + "\n");
        break;
      case '2' || '02':
        orng_jc_pumpId = pinPump1;
        Serial.println("Bomba 1 setada como: " + item_orng_jc_name + "\n");
        break;
      case '3' || '03':
       pneaple_jc_pumpId = pinPump1;
        Serial.println("Bomba 1 setada como: " + item_pneapple_jc_name + "\n");
        break;
      case '4' || '04':
        strwbrry_jc_pumpId = pinPump1;
        Serial.println("Bomba 1 setada como: " + item_strwbrry_jc_name + "\n");
        break;
      case '5' || '05':
        pssnft_jc_pumpId = pinPump1;
        Serial.println("Bomba 1 setada como: " + item_pssnft_jc_name + "\n");
        break;
      

     }

  }

}

void clear_data_received() {
  data_received = "";
  Serial.flush();
}

void serial_reader() {
  if (Serial.available() > 0) {
    char input_charvalue = Serial.read();
    data_received += input_charvalue;

    if (input_charvalue == '\n') {
      Serial.print("Dados recebidos: ");
      Serial.print(data_received);
    }
  }
}

void stop_all_pumps() {
  digitalWrite(pinPump1, LOW);
  digitalWrite(pinPump2, LOW);
  digitalWrite(pinPump3, LOW);
  digitalWrite(pinPump4, LOW);
  digitalWrite(pinPump5, LOW);
  Serial.println("Todas as bombas foram desligadas!\n\n");
  clear_data_received();
  delay(3000);
}

void first_drink() {
  Serial.println("\nNome: " + drink1_name + "\n");
  Serial.println("\nDescrição: " + drink1_desc + "\n");

  stop_all_pumps();

  float orng_jc_flowDelay = 0;
  float orng_jc_stopDelay = 0;

  float orng_jc_scnd_flowDelay = 0;
  float orng_jc_scnd_stopDelay = 0;

  float orng_jc_trd_flowDelay = 0;
  float orng_jc_trd_stopDelay = 0;

  //- Primeira etapa do Drink 1
  digitalWrite(pinPump00, HIGH);
  delay(orng_jc_flowDelay);
  digitalWrite(pinPump00, LOW);

  //- Intervalo para travar as bombas
  stop_all_pumps();
  delay(orng_jc_stopDelay); //- Intervalo do drink 1 etapa 1;

  //- Segunda etapa do Drink 1
  digitalWrite(pinPump00, HIGH);
  delay(orng_jc_scnd_flowDelay);
  digitalWrite(pinPump00, LOW);

  stop_all_pumps();
  delay(orng_jc_scnd_stopDelay); //- Intervalo Drink 1 etapa 2;

  //- Terceira etapa do Drink 1
  digitalWrite(pinPump00, HIGH);
  delay(orng_jc_trd_flowDelay);
  digitalWrite(pinPump00, LOW);

  //- Trava todas as bombas e finaliza o drink 1
  stop_all_pumps();
  clear_data_received();
  Serial.println("\nFinalizando Drink: " + drink1_name + "\n");
  delay(5000);
  // Abra o menu principal ou realize outras ações necessárias
  main_menu();
}

void begin_firstDrink(){

}

void pump_itemId_chk() {
  if (item_tonic_water && item_orange_juice && item_pineapple_juice && item_strawberry_juice && item_passionfruit_juice) {
    //Serial.println("_ #LOG: '\n");
    Serial.println("\n Elementos identificados: \n");
    Serial.println("");
  } else {
    Serial.println("\n_ #LOG: ERRO: Os ingredientes não estão disponíveis ou não foram configurados\n");
    Serial.println("\n_ #LOG: Iniciando Menu Principal\n");
    open_main_menu();
    Serial.println("_ #LOG: Menu Principal INICIANDO através da sub-função 'open_main_menu()'\n");
  }
}

void testPump(int numPumpLoop) {
  digitalWrite(numPumpLoop, HIGH);
  delay(5000);
  digitalWrite(numPumpLoop, LOW);
}

void test_menu() {
  Serial.println("\nMenu de Teste iniciado!");
  clear_data_received();

  Serial.println("\nSelecione uma opção:\n");
  Serial.println("\n1- Test Bomba 1\n2- Test Bomba 2\n3- Test Bomba 3\n4- Test Bomba 4\n5- Test Bomba 5\n0- Voltar \n\n\n");
  String opt_testmenu;
  serial_reader();
  opt_testmenu += data_received;

  if (opt_testmenu != '\n') {
    int selectedPump = opt_testmenu.charAt(5) - '0'; // Converter o caractere para inteiro

    if (selectedPump >= 1 && selectedPump <= 5) {
      Serial.print("Teste da Bomba ");
      Serial.print(selectedPump);
      Serial.println(" iniciado!");
      Serial.println("Iniciado em um Looping temporário...");
      delay(3000);
      testPump(selectedPump);
    } else if (selectedPump == 0) {
      Serial.println("Retornando...");
      clear_data_received();
      opt_testmenu = "";
      delay(2000);
      open_main_menu();
    } else {
      Serial.println("Opção não reconhecida");
    }
  }
}

void menu_drinks() {
  clear_data_received(); //- Limpa a string que armazena os dados, para captar mais dados;

  Serial.println("\nMenu de Drinks Iniciado!\n");
  delay(2000);
  Serial.println("\nEscolha uma das Opções:\n");
  Serial.println("\n1- Drink - Suco de Laranja c/Tônica\n2- Drink 2\n3- Drink 3\n4- Drink 4\n5- Água\n\n0- Voltar\n\n");
  serial_reader();

  String drink_option = data_received;

  if (drink_option != '\n') {
    int selectedDrink = drink_option.charAt(5) - '0'; // Converter o caractere para inteiro

    switch (selectedDrink) {
      case 1:
        Serial.println("\nDrink 'Suco de Laranja c/Tônica' selecionado!\n");
        begin_first_drink(); // Chama a função para abrir a função responsável por preparar o Drink 1
        break;
      case 2:
        Serial.println("\nDrink 2 selecionado!\n");
        // Adicione a lógica para preparar o Drink 2 aqui
        break;
      case 3:
        Serial.println("\nDrink 3 selecionado!\n");
        // Adicione a lógica para preparar o Drink 3 aqui
        break;
      case 4:
        Serial.println("\nDrink 4 selecionado!\n");
        // Adicione a lógica para preparar o Drink 4 aqui
        break;
      case 5:
        Serial.println("\nÁgua selecionada!\n");
        // Adicione a lógica para servir água aqui
        break;
      case 0:
        Serial.println("Retornando...");
        clear_data_received();
        delay(3000);
        break;
      default:
        Serial.println("Opção não reconhecida");
        break;
    }
  }
}

void main_menu() {
  Serial.println("\nSelecione um menu:\n");
  Serial.println("\n1- Drinks\n2-Menu de Teste\n0- Fechar\n");
  serial_reader();
  delay(3000);
  String send_chk_opt_str;
  send_chk_opt_str += data_received;

  switch (send_chk_opt_str.charAt(0)) {
    case '1':
      Serial.println("Opção 1 selecionada\n");
      Serial.println("Iniciando menu de Drinks...\n");
      delay(2000);
      menu_drinks();
      break;
    case '2':
      Serial.println("Opção 2 selecionada!\n");
      Serial.println("Iniciando menu de Teste...");
      delay(3000);
      test_menu();
      break;
    case '0':
      Serial.println("Fechando...");
      delay(2000);
      break;
    default:
      Serial.println("Opção não reconhecida");
      break;
  }
  data_received = ""; // Limpa a variável após processar a opção
}

void loop() {
  Serial.flush();
  Serial.println("Iniciando menu de opções...");
  main_menu();
}
