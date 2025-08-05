#define IN1 5  // Motor A direction
#define IN2 6  // Motor A direction
#define ENA 3  // Motor A speed (PWM)
#define IN3 9  // Motor B direction
#define IN4 10 // Motor B direction
#define ENB 11 // Motor B speed (PWM)

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  // Initialize motors to stopped state
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  Serial.println("Arduino Ready");
}