#include <EEPROM.h>

int num1 = 0;
int num2 = 0;
int address = 0; // Endereço da EEPROM

String entrada;

String lerLinha() {
  while (Serial.available() == 0);
  return Serial.readStringUntil('\n');
}

char lerOpcao() {
  entrada = lerLinha();
  return entrada.charAt(0);
}

int lerNumero() {
  entrada = lerLinha();
  return entrada.toInt();
}

void setup() {
  Serial.begin(9600);
}

void loop(){

  // EEPROM - salvar
  Serial.println("\nDeseja salvar um valor na EEPROM? (S/N)");
  char op = lerOpcao();

  if (op == 'S' || op == 's') {
    Serial.println("Digite o numero:");
    num1 = lerNumero();

    EEPROM.put(address, num1); // Armazena o valor da variavel num1 na EEPROM

    Serial.print("Salvo: ");
    Serial.println(num1); // Informa o numero que foi posto
  }

  // EEPROM - ler
  Serial.println("Deseja ver o valor na EEPROM? (S/N)");
  op = lerOpcao();

  if (op == 'S' || op == 's') {
    int valor = 0;
    EEPROM.get(address, valor); // lê o valor do endereço e armazena na varivel

    Serial.print("EEPROM: ");
    Serial.println(valor);
  }

  // Memoria Volátil - salvar
  Serial.println("Deseja salvar um valor na Memoria Volátil? (S/N)");
  op = lerOpcao();

  if (op == 'S' || op == 's') {
    Serial.println("Digite o numero:");
    num2 = lerNumero(); //Armazena o valor da variavel num2

    Serial.print("Memoria Volátil salva: ");
    Serial.println(num2);
  }

  // Memoria Volátil - ler
  Serial.println("Deseja ver o valor na Memoria Volátil? (S/N)");
  op = lerOpcao();

  if (op == 'S' || op == 's') {
    Serial.print("Memoria Volátil: ");
    Serial.println(num2); //le o valor da variavel num2
  }

  Serial.println("---- FIM ----");
  delay(2000);
  Serial.println("---- RECOMEÇO ----");
}