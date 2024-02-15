#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
// put function declarations here:
// int b2 = 2;
// int b3 = 3;
int b4 = 4; // TODO buzzer  vérifier si on peut ?
int b5 = 5; // que des boutons
int b6 = 6;
int b7 = 7;
int b8 = 8;
int b9 = 9;
int b10 = 10;
int b11 = 11;
int b12 = 12;
int b13 = 13;
boolean changement = false;
boolean lastState = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//? A0: Potentiomètre


void estHumide()
{
 //? avec false = sec et true = humide
  int valeurHumi = analogRead(A0);

  if (valeurHumi > 500)
  {
    changement = true;
     if(lastState != changement){
   //   Serial.println("changement vers humide");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Humide");
  }

  }
  else
  {
    changement = false;
     if(lastState != changement){
    //  Serial.println("changement vers sec");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sec");
  }

  }
  lastState = changement;
 
}

void afficherChiffre(int nbchar){
    String input = "";
String inputPrecedent = "";
    while (Wire.available()) {
      char b = Wire.read();
      input += b;
  }
  Serial.print(input);
  lcd.setCursor(0,1);
  lcd.print(input+"       ");
}

void setup()
{
  Wire.begin(1);
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  //! inutiles pinMode(b2, INPUT);
  //! inutiles pinMode(b3, INPUT);
  // pinMode(b4, OUTPUT); //? buzzer
  // pinMode(b5, INPUT);
  // pinMode(b6, INPUT);
  // pinMode(b7, INPUT);
  // pinMode(b8, INPUT);
  // pinMode(b9, INPUT);
  // pinMode(b10, INPUT);
  // pinMode(b11, INPUT);
  // pinMode(b12, INPUT);
  // pinMode(b13, INPUT);
  pinMode(A2, OUTPUT);
  analogWrite(A2, 100);
  pinMode(A0, INPUT); //? il s'agit du potentiomètre, ou du capteur d'humidité si on change
}

void loop()
{

  Wire.onReceive(afficherChiffre);

  
  delay(50);   // TODO a changer plus tard, c'est pour s'assurer que le micro controleur tourne pas en boucle pour rine
               // put your main code here, to run repeatedly:
               // estSurBord(); //
  estHumide(); 
}