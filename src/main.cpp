#include <Arduino.h>
#include <LibRobus.h>
#include <QTRSensors.h>

QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t sensors[8];


void setup() {
  BoardInit();
  Serial.begin(9600);

  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A1, A2, A3, A4, A5, A6, A7, A8}, SensorCount);
}

void avance(){
MOTOR_SetSpeed(RIGHT,0.3);
MOTOR_SetSpeed(LEFT,0.3);
}

void peu_droite(){ //le robot doit corriger sa trajectoire en allant un peu vers la droite
MOTOR_SetSpeed(RIGHT,0.27);
MOTOR_SetSpeed(LEFT,0.30);
}

void  peu_gauche(){
MOTOR_SetSpeed(RIGHT,0.30);
MOTOR_SetSpeed(LEFT,0.27);
}

void very_droite(){
MOTOR_SetSpeed(RIGHT,0.05);
MOTOR_SetSpeed(LEFT,0.20);
}

void very_gauche(){
MOTOR_SetSpeed(RIGHT,0.20);
MOTOR_SetSpeed(LEFT,0.05);
}

void stop(){
MOTOR_SetSpeed(RIGHT,0);
MOTOR_SetSpeed(LEFT,0);
}

void loop(){  
   // read raw sensor values
  qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  //delay(250);
/*
// CODE POUR LIGNE BLANCHE SUR FOND NOIR
  if (sensorValues[3] < 450 || sensorValues[4] < 450) // 2 capteurs du centre détectent ligne
  {
    avance();
  }
   if (sensorValues[5] < 500 || sensorValues[6] < 500) // si robot un peu trop à droite
  {
    peu_gauche();
  }
   if (sensorValues[1] < 500 || sensorValues[2] < 500 ) // si robot un peu trop à gauche
  {
    peu_droite();
  }
  
    if (sensorValues[7] < 600) // si robot bcp trop à droite
  {
    very_gauche();
  }
   if (sensorValues[0] < 600) // si robot bcp trop à gauche
  {
    very_droite();
  }
    if (sensorValues[1] < 600 && sensorValues[2] < 600  && sensorValues[3] < 600 && sensorValues[4] < 600  && sensorValues[5] < 600 && sensorValues[6] < 600  && sensorValues[7] < 600 && sensorValues[0] < 600) // si robot ne détecte pas de ligne
  {
    //Code de Mathieu pour qu'il fasse un tour et trouve la ligne
    stop();
  }*/
   /*
     if () // si robot détecte la puce RFID
  {
    stop();
    //Mise à état chercher capteur
  }*/
}

/* // CODE POUR LIGNE NOIR SUR FOND BLANC
  if (sensorValues[3] > 500 || sensorValues[4] > 500) // 2 capteurs du centre détectent ligne
  {
    avance();
  }
  
  if (sensorValues[5] > 600 || sensorValues[6] > 600) // si robot un peu trop à droite
  {
    peu_gauche();
  }
   if (sensorValues[1] > 600 || sensorValues[2] > 600 ) // si robot un peu trop à gauche
  {
    peu_droite();
  }
  
    if (sensorValues[7] > 700 ) // si robot bcp trop à droite
  {
    very_gauche();
  }
   if (sensorValues[0] > 700 ) // si robot bcp trop à gauche
  {
    very_droite();
  }
    if (sensorValues[1] > 400 && sensorValues[2] > 400  && sensorValues[3] > 400 && sensorValues[4] > 400  && sensorValues[5] > 400 && sensorValues[6] > 400  && sensorValues[7] > 400 && sensorValues[0] > 400) // si robot ne détecte pas de ligne
  {
    //Code de Mathieu pour qu'il fasse un tour et trouve la ligne
    stop();
  }
   /*
     if () // si robot détecte la puce RFID
  {
    stop();
    //Mise à état chercher capteur
  }*/