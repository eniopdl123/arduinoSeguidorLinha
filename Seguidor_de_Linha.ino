int MotorPin1 = 10;    //Motor Esquerdo
int sensorPin1 = 11;  //pino para receber o sinal do fototransistor Esquerdo
int MotorPin2 = 5;    //Motor Direito
int sensorPin2 = 6;  //pino para receber o sinal do fototransistor Direito
// Estado do sensor
int estado1;         //Esquerdo
int estado2;         //Direito
// Portas Analogicas
int sensor1analog = A1;
int sensor2analog = A2;
// Leitura das Portas Analogicas
int lsensor1analog;
int lsensor2analog;
// Ler a Plataforma Fita Preta ou Branca
int terreno;
//configurando os pinos (executado apenas uma vez)
void setup() {
  pinMode(MotorPin1, OUTPUT);  //definindo o pino do motor como saída
  pinMode(sensorPin1, INPUT); //definindo o pino do sensor como entrada
  pinMode(MotorPin2, OUTPUT);  //definindo o pino do motor como saída
  pinMode(sensorPin2, INPUT); //definindo o pino do sensor como entrada
  pinMode(sensor1analog, INPUT);
  pinMode(sensor2analog, INPUT);
  lsensor1analog = analogRead(sensor1analog);
  lsensor2analog = analogRead(sensor2analog);

  if (lsensor1analog < 100 && lsensor2analog < 100) {
    terreno = 1; //terrerno branco
  } else {
    terreno = 0; // terreno preto
  }
}

//laço principal (executado infinitamente)
void loop() {
  // Terreno com Fita Branca
  if (terreno = 1) {
    estado1 = digitalRead(sensorPin1); //lê o estado do sensor
    //verificando se o sensor detectou algum objeto ou não
    if (estado1 == HIGH) { //nenhum objeto detectado
      digitalWrite(MotorPin1, LOW); //apaga o LED indicador de presença de objeto
    } else { //objeto detectado
      digitalWrite(MotorPin1, HIGH); //acendo o LED indicador de presença de objeto
    }
    estado2 = digitalRead(sensorPin2); //lê o estado do sensor
    //verificando se o sensor detectou algum objeto ou não
    if (estado2 == HIGH) { //nenhum objeto detectado
      digitalWrite(MotorPin2, LOW); //apaga o LED indicador de presença de objeto
    } else { //objeto detectado
      digitalWrite(MotorPin2, HIGH); //acendo o LED indicador de presença de objeto
    }
  }
  // Terreno com Fita Preto
  else if (terreno = 0){
    estado1 = digitalRead(sensorPin1); //lê o estado do sensor 
    //verificando se o sensor detectou algum objeto ou não
    if (estado1 == LOW) { //nenhum objeto detectado
      digitalWrite(MotorPin1, LOW); //apaga o LED indicador de presença de objeto
    } else { //objeto detectado
      digitalWrite(MotorPin1, HIGH); //acendo o LED indicador de presença de objeto
    }
    estado2 = digitalRead(sensorPin2); //lê o estado do sensor
    //verificando se o sensor detectou algum objeto ou não
    if (estado2 == LOW) { //nenhum objeto detectado
      digitalWrite(MotorPin2, LOW); //apaga o LED indicador de presença de objeto
    } else { //objeto detectado
      digitalWrite(MotorPin2, HIGH); //acendo o LED indicador de presença de objeto
    }
    }
}
