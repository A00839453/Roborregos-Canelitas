void pid()
{
  proporcional = (p - 750);
  Serial.println(p);

  derivativo = proporcional - last_prop;
  integral = error1 + error2 + error3 + error4 + error5 + error6;

  last_prop = proporcional;
  error6 = error5;
  error5 = error4;
  error4 = error3;
  error3 = error2;
  error2 = error1;
  error1 = proporcional;
  
  //control PID
  diferencial = (proporcional * KP) + (derivativo * KD) + (integral * KI);
  
  if (diferencial > VelMax) diferencial = VelMax;
  else if (diferencial < -VelMax)diferencial = -VelMax;

  (diferencial < 0) ?
  Control.motores(VelMax + diferencial, VelMax) : Control.motores(VelMax, VelMax - diferencial);

}
