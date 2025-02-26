//Teste de comunicacao Node Red (serial)

#include  <Arduino.h>

#define entrada   4
#define LED1      2
#define sensor    35

byte  estadoatual = 1;
byte  ultimoestado;

int   leitura;

void  setup(){
  Serial.begin(9600);
  pinMode(entrada,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);
}

void  loop(){
  //GPIO 2
  if(Serial.available()){
    char rec = Serial.read();
    if(rec=='a')
      digitalWrite(LED1,1);
    else if(rec=='b')
      digitalWrite(LED1,0);
    Serial.flush();
  }

  //GPIO4
  estadoatual = digitalRead(entrada);
  if(estadoatual != ultimoestado){
    ultimoestado = estadoatual;
    Serial.print("X:");
    Serial.println(estadoatual);
  }

  //GPIO35
  leitura = analogRead(sensor);
  Serial.print("Y:");
  Serial.println(leitura);
  delay(300);
}