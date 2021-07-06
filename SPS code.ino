#include<LiquidCrystal.h>
LiquidCrystal lcd(1,2,7,6,5,4);

int a[6] = {9,8,10,13,11,12};
float duration, distance;

int DIST(int trigPin, int echoPin,int i)
{ int count=0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;
  
  
  if(distance<=10)
  {
  if(i==1)

  {
    lcd.setCursor(0,0);
    lcd.print("S1:P");
    count++;
  }
  else if(i==2)
  {
   lcd.setCursor(6,0);
   lcd.print("S2:P"); 
   count++;
  }
  else if(i==3)
  {
   lcd.setCursor(12,0);
   lcd.print("S3:P");
   count++; 
  }
  }
  else 
  {
    if(i==1)

  {
    lcd.setCursor(0,0);
    lcd.print("S1:F");
  }
  else if(i==2)
  {
   lcd.setCursor(6,0);
   lcd.print("S2:F"); 
  }
  else if(i==3)
  {
   lcd.setCursor(12,0);
  lcd.print("S3:F"); 
 }
  }
return count;
}

void setup() 
{
  int k=0;
  pinMode(3,OUTPUT);
  analogWrite(3,75);
  lcd.begin(16,2);
  while(k<6)
  {  
     pinMode(a[k], OUTPUT);
     pinMode(a[k+1], INPUT);
     k=k+2;
  }
  lcd.setCursor(0,0);
  lcd.print("F:Free");
  lcd.setCursor(0,1);
  lcd.print("P:Parked");
  lcd.clear();  
}

void loop() 
{ 
  int i=0;
  int j=1;
  int sum=0;
  delay(500);
  while(i<6)
  {
  sum = sum + DIST(a[i],a[i+1],j);
  i = i+2;
  j++; 
  }
  lcd.setCursor(0,1);
  lcd.print("Free Slots : ");
  lcd.print(3-sum);
}
