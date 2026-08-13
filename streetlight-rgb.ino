#define LDRPIN 10
#define IRPIN 9

const int redPin = 4;

void setColor(int red)
{
  analogWrite(redPin, red);

}
void setup()
{
  Serial.begin(9600);

  pinMode(LDRPIN, INPUT);
  pinMode(IRPIN, INPUT);
  pinMode(redPin, OUTPUT);
}

void loop()
{
  int a= digitalRead(LDRPIN);
  int b=digitalRead(IRPIN);
  Serial.println(a);
  Serial.println(b);

  if(a<=500 && b == 0)
  {
   setColor(150);
   delay(2000);
  }
  else if(a<=500 && b == 1)
  {
    setColor(255);
    delay(2000);
  }
  else
  {
    setColor(0);
    delay(2000);
  }
}
