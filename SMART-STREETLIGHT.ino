#define LEDPIN 10
#define LDRPIN 5
#define IRPIN 7
void setup()
{
 Serial.begin(9600);
 pinMode(LEDPIN,OUTPUT);
 pinMode(LDRPIN,INPUT);
 pinMode(IRPIN,INPUT);
}
void loop()
{
 int a=analogRead(LDRPIN);
 int b=digitalRead(IRPIN);
 if(a<500&&b<1)
{
  Serial.println(a);
  Serial.println(b);
  digitalWrite(LEDPIN, HIGH);
  delay(1000);
}
else
{
  Serial.println(a);
  Serial.println(b);
  digitalWrite(LEDPIN, LOW);
  delay(1000);
}
}
