//Programa: Arduino e bluetooth HC-05 com Blynk
//Autor: Arduino e Cia

//Emula a serial nos pinos digitais 4 e 5
#include <SoftwareSerial.h>
SoftwareSerial SerialBT(0, 1); // RX, TX

//Configuracoes biblioteca Blynk
#define BLYNK_PRINT SerialBT
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleSerialBLE.h>

//Token de autorizacao
char auth[] = "1f146b5f7f9e4d5599bc22c4cdf5df40";

void setup()
{
  //Inicializa a comunicacao serial com o modulo HC-05
  SerialBT.begin(9600);
  Blynk.begin(SerialBT, auth);
}

void loop()
{
  //Aguarda conexao e interpreta os comandos enviados
  Blynk.run();
}
