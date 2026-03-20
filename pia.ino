
//int led[] = {
//             32, 33, 25, 26, 27, 14, 12, 13
//};//          |   |   |   |   |   |   |   |
//            1   2   3   4   5   6   7   8

#define LED_COUNT 8
#define linii 13
#define CYCLES 10
#define DELAY_TIME 333 

int ledPins[LED_COUNT] = {32, 33, 25, 26, 27, 14, 12, 13}; 
int evenPattern[linii][LED_COUNT] = {
  {1, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 0, 0, 0, 0, 0}
};

void displayPattern(int pattern[]) {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], pattern[i]);
  }
  delay(DELAY_TIME);
}

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(115200);
  for (int cycle = 0; cycle < CYCLES; cycle++) {
    for (int pattern = 0; pattern < linii; pattern++) {
      displayPattern(evenPattern[pattern]);
    }
  }
digitalWrite(15, LOW);
digitalWrite(2, LOW);
digitalWrite(16, LOW);
}

void loop() {

  if (Serial.available() >= 5) { 
    int N1 = 0, N2 = 0;
    
    N1 = (Serial.read() - '0') * 10; 
    N1 += Serial.read() - '0'; 
    
    Serial.read();
    
    N2 = (Serial.read() - '0') * 10;
    N2 += Serial.read() - '0';
    
    

  if (N1 < 0 || N1 > 100 || N2 < 0 || N2 > 100) { 
    for (int i = 0; i < 5; i++) { 
      int oddPattern[LED_COUNT] = {1,0,1,0,1,0,1,0};
      displayPattern(oddPattern); 
      for (int i = 0; i < LED_COUNT; i++) {
      oddPattern[i] = (i % 2 == 0) ? 0 : 1; 
    }
      displayPattern(oddPattern);
    }
    digitalWrite(2, LOW);
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(21, LOW);
  } else { 
    int result=N1*N2;
    int ScriereBiti[LED_COUNT];
    int index=0;
    while (N1 > 0) {
        ScriereBiti[index++] = N1 % 2;
        N1 /= 2;
    }
    for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], ScriereBiti[i]);
    }
    delay(3000);
    for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], LOW);
    }
    index=0;
    while (N2 > 0) {
        ScriereBiti[index++] = N2 % 2;
        N2 /= 2;
    }
    for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], ScriereBiti[i]);
    }
    delay(3000);
    for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], LOW);
    }
    index=0;
    while (result > 0) {
for (index = 0; index <8; index++) {
       // int bit_value = (result >> index) & 1;
        //
      //  ScriereBiti[7 - index] = bit_value;
    
        ScriereBiti[index++] = result % 2;
        result /= 2;
    }
    }
    for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], ScriereBiti[i]);
    }
    delay(6000);
    for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], LOW);
}
}
}
}