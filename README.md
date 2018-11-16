# [OBJETOS INTELIGENTES CONECTADOS] 2º sem. 2018

## Turma 05K12
## Projeto: "CARRINHO DE CONTROLE REMOTO "
## Integrantes do grupo:

* Jefferson Guerra de Santana 
* Matheus Ribeiro Ferraz

## Descrição resumida do projeto

O objetivo desse projeto será construir um “Carinho de Controle” que será controlado através do celular via bluetooth que envia sinal para um receptor assim o lendo enviando para o protótipo arduino e que controla dois motores de corrente continua sendo que irá tanto para o lado direto, lado esquerdo e para frente. A lógica dele é bem simples e será criada para o entendimento de como usar o arduino, a linguagem C que é a mais simples para o entendimento será usada, neste projeto colocaremos em prática todo os conhecimentos adquiridos em mecânica, eletrônica e programação que tivermos ao longo do curso 

## Lista de Componentes 

* 1 Kit Chassi Acrílico de Carro com 2 motores DC 
* 1 Módulo Ponte H para Arduino - para 2 motores DC 12V
* 1 Arduinos UNO
* 1 Suportes para 4 Pilhas AA
* 2 Bateria 9V
* 1 Interruptor
* Fios e Conectores Dupont (Macho e Fêmea)
* 4 Pilhas AA
* 1 Baterias 9V

_______________________________________

## Código
//SERVO MOTOR SENTIDO HORARIO: IN1= 5V, IN2= GND
//SERVO MOTOR ANTI-HORARIO :   IN1= GDN, IN2= 5V

//Variaveis do tipo inteiras
#include <Servo.h>
int pos = 0;
Servo servo_8;

#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define leds 9
#define servo 8
int vel = 255;             // Velocidade dos motores (0-255)
int caracter = 'p';        // inicia desligado

#define pecho 2           
#define ptrig 3           
int tempo, distancia;      


void setup()  {
  Serial.begin(9600);    // inicia a Serial com bluetooth a 9600bps
  pinMode(in1, OUTPUT); // saida digital
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(leds, OUTPUT);

  pinMode(servo, OUTPUT);

  pinMode(pecho, INPUT);  
  pinMode(ptrig, OUTPUT);  
  pinMode(13, OUTPUT);
  servo_8.attach(8);

}

void loop()  {

  if (Serial.available() > 0) {    // lê o dado envido pelo blutooth e armazena na vriavel caracter
    caracter = Serial.read();
  }
  if ( caracter == 'f') {       // boato frente
    digitalWrite(in1, 0);
    analogWrite(in2, vel );
    analogWrite(in3, vel);
    analogWrite(in4, 0);

  }
  if (caracter == 'e') {      // botao esquerda
    analogWrite(in1, 0);
    analogWrite(in2, vel);
    analogWrite(in3, 0);
    digitalWrite(in4, 0);
  }
  if (caracter == 'p') {     // Botao Parar
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
  }
  if (caracter == 'd') {      // botao direita
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, vel);
    analogWrite(in4, 0);
  }
