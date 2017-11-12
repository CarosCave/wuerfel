int taste = PB0;

int zahl[7][4] = {
  {LOW, LOW, LOW, LOW}, // Null
  {HIGH, LOW, LOW, LOW}, // Eins
  {LOW, HIGH, LOW, LOW}, // Zwei
  {HIGH, LOW, HIGH, LOW}, // Drei
  {LOW, HIGH, HIGH, LOW}, // Vier
  {HIGH, HIGH, HIGH, LOW}, // Fünf
  {LOW, HIGH, HIGH, HIGH} // Sechs
};


int gruppe[4] = {PB4, PB3, PB2, PB1};

int seed __attribute__ ((section (".noinit"))); // Für den Zufallsgenerator

void setup() {
  pinMode(taste, INPUT_PULLUP);

  for(uint8_t i=0; i<4; i++) {
    pinMode(gruppe[i], OUTPUT);
    digitalWrite(gruppe[i], LOW);
  }

  // Zufallsgenerator
  randomSeed(seed);
}


void zahlZeigen(uint8_t wurf) {
  if (wurf < 7) {
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(gruppe[i], zahl[wurf][i]);
    }    
  }
  else {
    return;
  }
}


void loop() {
  uint8_t wurf = random(1, 7);
  uint8_t wuerfe = random(10, 100);
  int tastePush = digitalRead(taste);
  
  if(tastePush == LOW) {
    for(uint8_t i=0; i < wuerfe; i++) {   // Würfeln
      zahlZeigen(random(1, 7));
      delay(50);
    }
    zahlZeigen(0);
    delay(500);
    zahlZeigen(wurf);
    delay(500);
    zahlZeigen(0);
    delay(500);
    zahlZeigen(wurf);
    delay(2000);
    tastePush = HIGH;
    zahlZeigen(0);
  }
}
