#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

const short int buzzer = 6;

const int umidadeSoloPin = A0;

const int analogClickPin = 4;
const int analogVertPin = A1;
const int analogHorzPin = A2;

int umidadeAtualAnterior = -1;
int umidadeAtual;
int umidadePercentual;
int margemUmidadeAlta = 85;

String estados[] = {  "AC", "AL", "AM", "AP", "BA", "CE", "DF", "ES", "GO",
                      "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI",
                      "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
int totalEstados = sizeof(estados) / sizeof(estados[0]);
String estadoSelecionado = "";

int analogXaxis(){
  return map(analogRead(analogHorzPin), 0, 1023, 100, -100);
}
int analogYaxis(){
  return map(analogRead(analogVertPin), 0, 1023, -100, 100);
}
int analogInput(){
  if (analogXaxis() > 50) { //Direita
    return 1;
  }  
  if (analogXaxis() < -50) { //Esquerda
    return 2;
  }
  if (analogYaxis() > 50) { //Cima
    return 3;
  }  
  if (analogYaxis() < -50) { //Baixo
    return 4;
  }
  if (digitalRead(analogClickPin) == LOW){ //Click
    return 5;
  }
  return 0;
}

void startAnim() {
  lcd.clear();
  lcd.setCursor(3, 0);

  String texto = "FloodSafe";
  for (int i = 0; i < texto.length(); i++) {
    lcd.print(texto[i]);
    delay(90);
  }

  delay(2000);
}

void configurarEstado() {
  int index = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Config. Estado");

  while (true) {
    lcd.setCursor(5, 1);
    lcd.print("< " + estados[index] + " >");

    delay(150);

    if (analogInput() == 1 && index < totalEstados - 1) {
      index++;
      delay(300);
    } else if (analogInput() == 2 && index > 0) {
      index--;
      delay(300);
    }

    if (analogInput() == 5) {
      estadoSelecionado = estados[index];
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Estado: " + estadoSelecionado);
      delay(3000);
      break;
    }
  }
}

void menuConfig() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estado atual:");
  lcd.print(estadoSelecionado);
  lcd.setCursor(0, 1);
  lcd.print("Click p/ mudar >");

  while (true){
    lcd.setCursor(0, 0);
    if (analogInput() == 5){
      configurarEstado();
      lcd.clear();
      umidadeAtualAnterior = -1;
      break;
    }
    if (analogInput() == 1){
      lcd.clear();
      umidadeAtualAnterior = -1;
      break;
    }
  }
}

void setup() {
  //buzzer
  pinMode(buzzer, OUTPUT);

  //ANALOG
  pinMode(analogClickPin, INPUT_PULLUP);
  pinMode(analogVertPin, INPUT);
  pinMode(analogHorzPin, INPUT);

  //LCD
  lcd.init();
  lcd.backlight();

  startAnim();
  configurarEstado();
}

void loop() {

  if (umidadeAtualAnterior != umidadeAtual) {
    umidadeAtualAnterior = umidadeAtual;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Umid. solo: ");
    lcd.print(umidadePercentual);
    lcd.print("%");

    lcd.setCursor(0, 1);
    if (umidadePercentual >= margemUmidadeAlta) {
      lcd.print("<    Alta!!    >");
      tone(buzzer, 131, 3000);
    }
    else {
      lcd.print("<    Normal    >");
      noTone(buzzer);
    }
  }
  umidadeAtual = analogRead(umidadeSoloPin);
  umidadePercentual = map(analogRead(umidadeSoloPin), 0, 1023, 0, 100);

  if(analogInput() == 2) {
    menuConfig();
  }
}
