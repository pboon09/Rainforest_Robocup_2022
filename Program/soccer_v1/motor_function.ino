void motor1(int p) {
  int power = constrain(p, -255, 255);
  if (power < 0) {
    analogWrite(motor1ena, power * -1);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
  }
  else if (power >= 0) {
    analogWrite(motor1ena, power);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  }
}

void motor2(int p) {
  int power = constrain(p, -255, 255);
  if (power < 0) {
    analogWrite(motor2ena, power * -1);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
  }
  else if (power >= 0) {
    analogWrite(motor2ena, power);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  }
}

void motor3(int p) {
  int power = constrain(p, -255, 255);
  if (power < 0) {
    analogWrite(motor3ena, power * -1);
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);
  }
  else if (power >= 0) {
    analogWrite(motor3ena, power);
    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);
  }
}

void motor4(int p) {
  int power = constrain(p, -255, 255);
  if (power < 0) {
    analogWrite(motor4ena, power * -1);
    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);
  }
  else if (power >= 0) {
    analogWrite(motor4ena, power);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);
  }
}

void ao() {
  digitalWrite(motor1ena, HIGH);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2ena, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, HIGH);

  digitalWrite(motor3ena, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, HIGH);

  digitalWrite(motor4ena, HIGH);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, HIGH);
}
