void attacker(int da) {
  while (true) {
    ms.write(0);
    InfraredResult InfraredBall = InfraredSeeker::ReadAC();
    int DIR = InfraredBall.Direction;
    int STR = InfraredBall.Strength;

    a = Compass.GetHeadingDegrees();

    int angle = a - da;
    if (a - da < 0) {
      angle = 360 + a - da;
    }
    if (angle > 180) {
      angle -= 360;
    }

    error = 0 - angle;
    int delta_angle = constrain(1.7 * (error * Kp + (error - last_error) * Kd), -255, 255);

    if (!(STR >= STR_FILTER) || (!((DIR >= IR_LOWER_BOUND) && (DIR <= IR_HIGHER_BOUND)))) {
      DIR = 0;
    }

    IR = constrain(((DIR * 36) - 180) * 1.3, -180, 180);

    found = false;
    sen = 0;

    if (analogRead(light[0]) > 600) {
      found = true;
      sen = 0;
    }
    if (analogRead(light[1]) > 550) {
      found = true;
      sen = 1;
    }
    else if (analogRead(light[2]) > 690) {
      found = true;
      sen = 2;
    }
    else if (analogRead(light[3]) > 530 ) {
      found = true;
      sen = 3;
    }
    else if (analogRead(light[4]) > 610) {
      found = true;
      sen = 4;
    }
    else if (analogRead(light[5]) > 590) {
      found = true;
      sen = 5;
    }
    else if (analogRead(light[6]) > 640) {
      found = true;
      sen = 6;
    }
    else if (analogRead(light[7]) > 640) {
      found = true;
      sen = 7;
    }

    if (analogRead(ball_found) > ball) {
      sp_dic = ((STR * -0.004) + 1) * sp;
    }
    else if (analogRead(ball_found) < ball) {
      sp_dic = 280;
      ms.write(180);
    }

    p1 = sp_dic * cos((PI * (-45 + IR)) / 180) + delta_angle;
    p2 = sp_dic * cos((PI * (45 + IR)) / 180) - delta_angle;
    p3 = sp_dic * cos((PI * (45 + IR)) / 180) + delta_angle;
    p4 = sp_dic * cos((PI * (-45 + IR)) / 180) - delta_angle;

    //    p1 = 0 * cos((PI * (-45 + IR)) / 180) + delta_angle;
    //    p2 = 0 * cos((PI * (45 + IR)) / 180) - delta_angle;
    //    p3 = 0 * cos((PI * (45 + IR)) / 180) + delta_angle;
    //    p4 = 0 * cos((PI * (-45 + IR)) / 180) - delta_angle;

    if (found == true) {
      break;
    }
    if (found == false) {
      motor1(p1);
      motor2(p2);
      motor3(p3);
      motor4(p4);
    }
    Serial.println("1");
    last_error = error;
  }
}
