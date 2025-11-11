#include <Servo.h>

// Cria os objetos dos servos
Servo baseServo;
Servo ombroServo;

// Configurações do servo base
const int PINO_SERVO_BASE = A1;
const int ANGULO_MINIMO_BASE = 0;
const int ANGULO_MAXIMO_BASE = 145;
const int VELOCIDADE_BASE = 20;  // ms entre cada grau

// Configurações do servo ombro
const int PINO_SERVO_OMBRO = A2;
const int ANGULO_MINIMO_OMBRO = 0;
const int ANGULO_MAXIMO_OMBRO = 145;
const int VELOCIDADE_OMBRO = 20;  // ms entre cada grau

void setup() {
  inicializarComunicacaoSerial();
  inicializarServoBase();
  inicializarServoOmbro();
  exibirConfiguracoesServoBase();
  exibirConfiguracoesServoOmbro();
  moverServoBaseParaPosicaoInicial();
  moverServoOmbroParaPosicaoInicial();
}

void loop() {
  executarMovimentoIdaServoBase();
  executarPausaNoMaximoServoBase();
  executarMovimentoVoltaServoBase();
  executarPausaNoMinimoServoBase();
}

// ========== FUNÇÕES DE INICIALIZAÇÃO ==========

void inicializarComunicacaoSerial() {
  Serial.begin(9600);
  
  // Aguarda a porta serial conectar 
  while (!Serial) {
    delay(10);
  }
  
  Serial.println("=== Controle de Servo Motor Base ===");
}

void inicializarServoBase() {
  baseServo.attach(PINO_SERVO_BASE);
}

void exibirConfiguracoesServoBase() {
  Serial.print("[SERVO-BASE] Range angular: ");
  Serial.print(ANGULO_MINIMO_BASE);
  Serial.print(" a ");
  Serial.print(ANGULO_MAXIMO_BASE);
  Serial.println(" graus");
  
  Serial.print("[SERVO-BASE] Velocidade: ");
  Serial.print(VELOCIDADE_BASE);
  Serial.println(" ms/grau");
  
  Serial.println("[SERVO-BASE] Servo base inicializado e pronto para movimento");
  delay(1000);
}

// ========== FUNÇÕES DE MOVIMENTO ==========

void moverServoBaseParaPosicaoInicial() {
  Serial.println("[SERVO-BASE] Posicionando servo na posição inicial...");
  baseServo.write(ANGULO_MINIMO_BASE);
  delay(500);
}

void executarMovimentoIdaServoBase() {
  Serial.println("[SERVO-BASE] --- MOVIMENTO DE IDA ---");
  
  for (int angulo = ANGULO_MINIMO_BASE; angulo <= ANGULO_MAXIMO_BASE; angulo++) {
    moverServoBaseParaAngulo(angulo);
  }
  
  Serial.println("[SERVO-BASE] Movimento de ida concluído");
}

void executarMovimentoVoltaServoBase() {
  Serial.println("[SERVO-BASE] --- MOVIMENTO DE VOLTA ---");
  
  for (int angulo = ANGULO_MAXIMO_BASE; angulo >= ANGULO_MINIMO_BASE; angulo--) {
    moverServoBaseParaAngulo(angulo);
  }
  
  Serial.println("[SERVO-BASE] Movimento de volta concluído");
}

void executarPausaNoMaximoServoBase() {
  Serial.println("[SERVO-BASE] Pausa no ponto máximo...");
  delay(1000);
}

void executarPausaNoMinimoServoBase() {
  Serial.println("[SERVO-BASE] Pausa no ponto mínimo...");
  delay(1000);
}

// ========== FUNÇÕES DE CONTROLE DO SERVO ==========

void moverServoBaseParaAngulo(int angulo) {
  baseServo.write(angulo);
  exibirPosicaoAtualServoBase(angulo);
  controlarVelocidadeMovimentoServoBase();
}

void exibirPosicaoAtualServoBase(int angulo) {
  Serial.print("[SERVO-BASE] Movendo para: ");
  Serial.print(angulo);
  Serial.println("°");
}

void controlarVelocidadeMovimentoServoBase() {
  delay(VELOCIDADE_BASE);
}

// ========== FUNÇÕES DO OMBRO ===========

void inicializarServoOmbro() {
  ombroServo.attach(PINO_SERVO_OMBRO);
  Serial.println("[SERVO-OMBRO] Servo do ombro inicializado");
}

void exibirConfiguracoesServoOmbro() {
  Serial.print("[SERVO-OMBRO] Range angular: ");
  Serial.print(ANGULO_MINIMO_OMBRO);
  Serial.print(" a ");
  Serial.print(ANGULO_MAXIMO_OMBRO);
  Serial.println(" graus");
  
  Serial.print("[SERVO-OMBRO] Velocidade: ");
  Serial.print(VELOCIDADE_OMBRO);
  Serial.println(" ms/grau");
  
  Serial.println("[SERVO-OMBRO] Servo ombro inicializado e pronto para movimento");
}

void moverServoOmbroParaPosicaoInicial() {
  Serial.println("[SERVO-OMBRO] Posicionando ombro na posição inicial...");
  ombroServo.write(ANGULO_MINIMO_OMBRO);
  delay(500);
}

void executarMovimentoIdaServoOmbro() {
  Serial.println("[SERVO-OMBRO] --- MOVIMENTO DE IDA DO OMBRO ---");
  
  for (int angulo = ANGULO_MINIMO_OMBRO; angulo <= ANGULO_MAXIMO_OMBRO; angulo++) {
    moverServoOmbroParaAngulo(angulo);
  }
  
  Serial.println("[SERVO-OMBRO] Movimento de ida do ombro concluído");
}

void executarMovimentoVoltaServoOmbro() {
  Serial.println("[SERVO-OMBRO] --- MOVIMENTO DE VOLTA DO OMBRO ---");
  
  for (int angulo = ANGULO_MAXIMO_OMBRO; angulo >= ANGULO_MINIMO_OMBRO; angulo--) {
    moverServoOmbroParaAngulo(angulo);
  }
  
  Serial.println("[SERVO-OMBRO] Movimento de volta do ombro concluído");
}

void executarPausaNoMaximoServoOmbro() {
  Serial.println("[SERVO-OMBRO] Pausa no ponto máximo do ombro...");
  delay(1000);
}

void executarPausaNoMinimoServoOmbro() {
  Serial.println("[SERVO-OMBRO] Pausa no ponto mínimo do ombro...");
  delay(1000);
}

void moverServoOmbroParaAngulo(int angulo) {
  ombroServo.write(angulo);
  exibirPosicaoAtualServoOmbro(angulo);
  controlarVelocidadeMovimentoServoOmbro();
}

void exibirPosicaoAtualServoOmbro(int angulo) {
  Serial.print("[SERVO-OMBRO] Movendo para: ");
  Serial.print(angulo);
  Serial.println("°");
}

void controlarVelocidadeMovimentoServoOmbro() {
  delay(VELOCIDADE_OMBRO);
}