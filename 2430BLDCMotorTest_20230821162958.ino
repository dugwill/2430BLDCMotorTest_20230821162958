unsigned long time = 0, lp = 0, hp = 0;
float pa, rpm;
int samples = 20;
int speed =255;
bool direction = HIGH;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(10, OUTPUT);  //direction control 
  pinMode(11, OUTPUT);  //PWM PIN 11  with PWM wire
  pinMode(12, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10, direction);

  analogWrite(11, speed);

  for (int j = 0; j < samples; j++) {
    hp += pulseIn(12, HIGH, 30000);
    lp += pulseIn(12, LOW, 30000);
  }
  hp = hp/samples;
  lp = lp/samples;
  pa = hp + lp;
  rpm = 1/(pa/1000000); //Pulse Frequency
  rpm = rpm/9;    // Motor rps
  rpm = rpm*60;   // Motor rpm
  rpm = rpm/35.5;  // output rpm
  Serial.print(hp); 
  Serial.print("  hpa  ");
  Serial.print(lp); 
  Serial.print("  lpa  ");
  Serial.print(pa,3); 
  Serial.print("  atp  ");
  Serial.print(rpm,3); 
  Serial.println("  rpm");

  hp = 0;
  lp = 0;
}