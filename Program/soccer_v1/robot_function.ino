void white_line(int da) {
  float Last_time = millis();
  while (millis() - Last_time < 400) {
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

    if (sen == 0 || sen == 1) {
      IR = 180;
    }
    else if (sen == 2 || sen == 3) {
      IR = 90;
    }
    else if (sen == 4 || sen == 5) {
      IR = 0;
    }
    else if (sen == 6 || sen == 7) {
      IR = -90;
    }

    p1 = 150 * cos((PI * (-45 + IR)) / 180) + delta_angle;
    p2 = 150 * cos((PI * (45 + IR)) / 180) - delta_angle;
    p3 = 150 * cos((PI * (45 + IR)) / 180) + delta_angle;
    p4 = 150 * cos((PI * (-45 + IR)) / 180) - delta_angle;

    motor1(p1);
    motor2(p2);
    motor3(p3);
    motor4(p4);
    Serial.println("2");
    last_error = error;
  }
  found = false;
}
