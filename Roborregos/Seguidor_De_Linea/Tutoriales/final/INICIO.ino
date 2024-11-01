void calibracion()
{
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_pixelmordred_tr);
  u8g2.drawStr(1, 15, "Team Dragones");
  u8g2.sendBuffer();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso28_tr);
  u8g2.drawStr(20, 30, "Blanco");
  u8g2.sendBuffer();
  waitBoton();
  Robot.leer_blanco();
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso28_tr);
  u8g2.drawStr(20, 30, "Negro");
  u8g2.sendBuffer();
  waitBoton();
  Robot.leer_negro();
  delay(2000);
  Robot.Calcula_muestras();
  
 
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso28_tr);
  u8g2.drawStr(20, 30, "REDY");
  u8g2.sendBuffer();

}
