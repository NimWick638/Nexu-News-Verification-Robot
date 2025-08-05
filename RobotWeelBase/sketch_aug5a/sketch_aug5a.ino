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

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read incoming serial data
    // Print raw ASCII value for debugging
    Serial.print("Received ASCII: ");
    Serial.println((int)command);
    // Ignore newline (10) and carriage return (13)
    if (command == '\n' || command == '\r') {
      return;
    }
    // Process command
    switch (command) {
      case 'F': // Move Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        Serial.println("Moving Forward");
        break;
      case 'B': // Move Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        Serial.println("Moving Backward");
        break;
      case 'L': // Turn Left
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 150);
        analogWrite(ENB, 150);
        Serial.println("Turning Left");
        break;
      case 'R': // Turn Right
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 150);
        analogWrite(ENB, 150);
        Serial.println("Turning Right");
        break;
      case 'S': // Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        Serial.println("Stopped");
        break;
      default:
        Serial.print("Invalid Command: ");
        Serial.println(command);
        break;
    }
  }
}