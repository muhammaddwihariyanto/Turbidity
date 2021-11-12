int pinTurb = A0;
float V;
float kekeruhan;
float VRata2;
float VHasil;
int samples = 800;
void setup()
{
  Serial.begin(9600);
  Serial.println("SENSOR KEKERUHAN AIR");
  delay(2000);
}

void loop()
{
  V = 0;
  for(int i=0; i<samples; i++)
  {
    V += ((float)analogRead(pinTurb)/1023)*5;
    delay(1);
  }

  VRata2 = V/samples;
  VHasil = roundf(VRata2*10.0f)/10.0f;

  if(VHasil < 2.5)
  {
    kekeruhan = 3000;
  }
  else
  {
    kekeruhan = -1120.4*square(VHasil)+5742.3*VHasil-4353.9;
  }

  Serial.print("tegangan :");
  Serial.print(VHasil);
  Serial.print(" V");

  Serial.print("\t kekeruhan :");
  Serial.println(kekeruhan/100);
  delay(10);
}
