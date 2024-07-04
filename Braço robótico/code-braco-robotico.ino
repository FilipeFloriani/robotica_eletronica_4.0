#include <Servo.h>

#define ANGULO_INICIAL_MOTOR 90

#define joy1X A0 // azul
#define joy1Y A1 // roxo

#define joy2X A2 // azul
#define joy2Y A3 // roxo

Servo motorBase;
Servo motorBraco1;
Servo motorBraco2;
Servo motorGarra;

void setup() {
  mapeamentoPinosServos();
  inicializacaoAngulosServos();
  mapeamentoJoystickComoInput();
  Serial.begin(9600);
}

void loop() {
  moverBase();
  moverBraco1();
  //moverBraco2();
  //moverGarra();

  delay(100);
}

// ------- Funções auxiliares -------

// Mapeamento dos pinos dos servos
void mapeamentoPinosServos(){
  motorBase.attach(5);
  motorBraco1.attach(6);
  //motorBraco2.attach(9);
  //motorGarra.attach(10);
}

// Inicialização dos angulos dos motores
void inicializacaoAngulosServos(){
    motorBase.write(ANGULO_INICIAL_MOTOR);
    motorBraco1.write(ANGULO_INICIAL_MOTOR);
    motorBraco2.write(ANGULO_INICIAL_MOTOR);
    //delay(2000);
    //motorBraco2.write(60);
    motorGarra.write(ANGULO_INICIAL_MOTOR);

    Serial.println("inicialiando angulos");
}

// Mapear os pinos do joystick como INPUT
void mapeamentoJoystickComoInput(){
  pinMode(joy1X, INPUT);
  pinMode(joy1Y, INPUT);
  pinMode(joy2X, INPUT);
  pinMode(joy2Y, INPUT);
}

// Mover Base
void moverBase(){
  int posX = analogRead(joy1X);
  posX = map(posX, 0, 1023, 0, 180);
  motorBase.write(posX);
}

// Mover braço 1
void moverBraco1(){
  int posY = analogRead(joy1Y);
  posY = map(posY, 0, 1023, 55, 150);
  motorBraco1.write(posY);
}

// Mover braço 2
void moverBraco2(){
  int posX = analogRead(joy2X);
  posX = map(posX, 0, 1023, 40, 60);
  motorBraco2.write(posX);

 Serial.println(posX); 
}

// Mover garra
void moverGarra(){
  int posY = analogRead(joy2Y);
  posY = map(posY, 0, 1023, 90, 130);
  motorGarra.write(posY);
}
