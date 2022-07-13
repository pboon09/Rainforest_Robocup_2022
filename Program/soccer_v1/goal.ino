void goal(int da) {
  while (true) {
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

    error = initial_angle - angle;
    int delta_angle = constrain(6 * (error * Kp + (error - last_error) * Kd), -255, 255);


    if (DIR != 5) {
      if (DIR > 5) {
        IR = 90;
        sp_dic = 400;
      }
      else if (DIR < 5) {
        IR = -90;
        sp_dic = 400;
      }
    }
    else {
      sp_dic = 0;
      ao();
      //check str and bt signal
    }

    if (sp_dic != 0) {
      p1 = sp_dic * cos((PI * (-45 + IR)) / 180) + delta_angle;
      p2 = sp_dic * cos((PI * (45 + IR)) / 180) - delta_angle;
      p3 = sp_dic * cos((PI * (45 + IR)) / 180) + delta_angle;
      p4 = sp_dic * cos((PI * (-45 + IR)) / 180) - delta_angle;

      motor1(p1);
      motor2(p2);
      motor3(p3);
      motor4(p4);
    }
    if (sp_dic == 0) {
      ao();
    }
    last_error = error;
  }
}
