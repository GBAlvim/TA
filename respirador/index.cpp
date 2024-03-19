int bits = 0;
int led = 3;
int increment = 5; 
int duration = 2000; 
bool breathingIn = true;

void breathe() {
  if (breathingIn) {
    
    for (bits = 0; bits <= 255; bits += increment) {
      analogWrite(led, bits); 
      delay(duration / 51); 
    }
  } else {
    
    for (bits = 255; bits >= 0; bits -= increment) {
      analogWrite(led, bits); 
      delay(duration / 51); 
    }
  }
  breathingIn = !breathingIn; 
}

void setup() {
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  breathe(); 
}