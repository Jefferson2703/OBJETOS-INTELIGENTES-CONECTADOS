//SERVO MOTOR SENTIDO HORARIO: IN1= 5V, IN2= GND
//SERVO MOTOR ANTI-HORARIO :   IN1= GDN, IN2= 5V

//Variaveis do tipo inteiras
#include <SoftwareSerial.h>

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

#define pecho 2           // define o pino 2 para o retorno do ultrasson
#define ptrig 3            // define o pino 3 para o trig do ultrasson
int tempo, distancia;      // para Calcular distacia

void setup()  {
  Serial.begin(9600);    // inicia a Serial com bluetooth a 9600bps

  pinMode(in1, OUTPUT); // saida digital
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(leds, OUTPUT);

  pinMode(servo, OUTPUT);

  pinMode(pecho, INPUT);   // define el pin 2 como entrada (pecho)
  pinMode(ptrig, OUTPUT);  // define el pin 3 como salida  (ptrig)
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

  if (caracter == 'r') {      // botao Ré
    analogWrite(in1, vel);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, vel);
  }



  if (caracter == 'l') {      // Liga farois
    digitalWrite(leds, 1);

  }
  if (caracter == 'g') {      // Liga farois
    digitalWrite(leds, 0);

  }
  if (caracter == 'a') {        // controle de obstaculo

    digitalWrite(ptrig, HIGH);   // gera um pulso de trigger por 10us
    delayMicroseconds(10);
    digitalWrite(ptrig, LOW);

    tempo = pulseIn(pecho, HIGH);          // Lê o tempo do Echo
    distancia = (tempo / 2) / 29;          // calcula a distancia em centimetros
    delay(10);

    if (distancia <= 20) {                  // se a distancia for menor ou igual a  5cm
      digitalWrite(13, HIGH);             // acende um led

      analogWrite(in1, 0);             // para os motores por 200 mili segundos
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
      delay (200);

      analogWrite(in1, vel);         //da ré por 500 mili segundos
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, vel);
      delay(500);

      analogWrite(in1, 0);            // gira para a esquerda por 600 mili segundos
      analogWrite(in2, 0);
      analogWrite(in3, vel);
      analogWrite(in4, 0);
      delay(600);



      digitalWrite(13, LOW);
    }
    else {                            //se não houver obstaculos continua em frente
      analogWrite(in1, 0);
      analogWrite(in2, vel);
      analogWrite(in3, vel);
      analogWrite(in4, 0);
    }
  }
  if  (caracter == 'b') {       // desliga os motores
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
  }


}
