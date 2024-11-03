void setup()
{
  pinMode(11, OUTPUT); //led on  1 = on ---- 0 = off
  pinMode(14, OUTPUT); //A0=S0
  pinMode(15, OUTPUT); //A1=S1
  pinMode(16, OUTPUT); //A2=S2
  pinMode(17, OUTPUT); //A3=S3
  Serial.begin(9600);
}

void loop()
{
  for (int canal=0;canal<=15;canal++)
  {
    switch (canal)
    {
      case 0:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //LOW=0
        digitalWrite(15, LOW); //0
        digitalWrite(16, LOW); //0
        digitalWrite(17, LOW); //0
        break;
      case 1:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, LOW); //0
        digitalWrite(16, LOW); //0
        digitalWrite(17, LOW); //0
        break;
      case 2:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, HIGH); //1
        digitalWrite(16, LOW); //0
        digitalWrite(17, LOW); //0
        break;
      case 3:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, HIGH); //1
        digitalWrite(16, LOW); //0
        digitalWrite(17, LOW); //0
        break;
      case 4:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, LOW); //0
        digitalWrite(16, HIGH); //1
        digitalWrite(17, LOW); //0
        break;
      case 5:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, LOW); //0
        digitalWrite(16, HIGH); //1
        digitalWrite(17, LOW); //0
        break;
      case 6:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, HIGH); //1
        digitalWrite(16, HIGH); //1
        digitalWrite(17, LOW); //0
        break;
      case 7:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, HIGH); //1
        digitalWrite(16, HIGH); //1
        digitalWrite(17, LOW); //0
        break;
      case 8:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, LOW); //0
        digitalWrite(16, LOW); //0
        digitalWrite(17, HIGH); //1
        break;
      case 9:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, LOW); //0
        digitalWrite(16, LOW); //0
        digitalWrite(17, HIGH); //1
        break;
      case 10:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, HIGH); //1
        digitalWrite(16, LOW); //0
        digitalWrite(17, HIGH); //1
        break;
      case 11:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, HIGH); //1
        digitalWrite(16, LOW); //0
        digitalWrite(17, HIGH); //1
        break;
      case 12:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, LOW); //0
        digitalWrite(16, HIGH); //1
        digitalWrite(17, HIGH); //1
        break;
      case 13:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, LOW); //0
        digitalWrite(16, HIGH); //1
        digitalWrite(17, HIGH); //1
        break;
      case 14:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, LOW); //0
        digitalWrite(15, HIGH); //1
        digitalWrite(16, HIGH); //1
        digitalWrite(17, HIGH); //1
        break;
      case 15:
        digitalWrite(11, HIGH); //HIGH=1
        digitalWrite(14, HIGH); //1
        digitalWrite(15, HIGH); //1
        digitalWrite(16, HIGH); //1
        digitalWrite(17, HIGH); //1
        break;
    }
    Serial.print("S");
    Serial.print(canal);
    Serial.print("=");
    Serial.print(analogRead(A6));
    Serial.print(" ");
  }

  Serial.println();
}
