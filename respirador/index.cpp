// Definindo variáveis
int bits = 0;
int led = 3;

// Variáveis para controle da respiração
int increment = 5; // Incremento de brilho
int duration = 2000; // Tempo total de respiração em milissegundos (2 segundos)

// Flag para controle da direção da respiração
bool breathingIn = true;

// Função de respiração
void breathe() {
  if (breathingIn) {
    // Crescimento (0% a 100%)
    for (bits = 0; bits <= 255; bits += increment) {
      analogWrite(led, bits); // Define a intensidade do LED
      delay(duration / 51);   // Delay proporcional ao tempo total e ao número de incrementos
    }
  } else {
    // Decaimento (100% a 0%)
    for (bits = 255; bits >= 0; bits -= increment) {
      analogWrite(led, bits); // Define a intensidade do LED
      delay(duration / 51);   // Delay proporcional ao tempo total e ao número de incrementos
    }
  }
  breathingIn = !breathingIn; // Inverte a direção da respiração
}

//void Setup
void setup() {
  pinMode(led, OUTPUT);
  
  //Monitor Serial
  Serial.begin(9600);
}

//void loop
void loop() {
  breathe(); // Chama a função de respiração
}