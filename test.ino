#define ENA 12
#define IN1 3
#define IN2 4
#define ENB 5
#define IN3 6
#define IN4 7
#define LED_PIN 9
#define SW 2

int sec_time = 3 * 1000;   // 단위 초

const byte sensor = 10;

unsigned long prev_time = 0;

bool runState = false;

void setup()
{
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(SW), stateChange, RISING);

  pinMode(sensor, INPUT_PULLUP);
}

void right() {
  Serial.println(" 오른쪽으로 도는중 ");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1);
}

void left() {
  Serial.println(" 왼쪽으로 도는중 ");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1);
}

void stateChange() {
  prev_time = millis();
  runState = !runState;
}

void wipe() {
  Serial.println("wipe start!");
  digitalWrite(LED_PIN, HIGH);
  do {
    right();
    Serial.println(millis() - prev_time);
  } while (millis() - prev_time < sec_time);
  prev_time = millis();
  do {
    left();
    Serial.println(millis() - prev_time);
  } while (millis() - prev_time < sec_time);
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  if (runState) {
    wipe();
    stateChange();
  }
  else{
    
  }
}
