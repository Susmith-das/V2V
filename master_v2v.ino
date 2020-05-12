#define lmf 13 //left motors forward
#define lmb 12 //left motors reverse
#define rmf 11 //right motors forward
#define rmb 10 //right motors reverse
#define f 9 //encoder data
#define b 8 //encoder data
#define l 7 //encoder data
#define r 6 //encoder data

char t;

void setup()
{
pinMode(lmf,OUTPUT);  
pinMode(lmb,OUTPUT);   
pinMode(rmf,OUTPUT);   
pinMode(rmb,OUTPUT);
pinMode(f,OUTPUT);
pinMode(b,OUTPUT);
pinMode(l,OUTPUT);
pinMode(r,OUTPUT);   
Serial.begin(9600);
}
 
void loop()
{
  if(Serial.available())
  {
    t = Serial.read();
    Serial.println(t);
    sendit(t);
    switch(t)
    {
      case 'F': //move forward
                digitalWrite(lmf,HIGH);
                digitalWrite(rmf,HIGH);
                digitalWrite(lmb,LOW);
                digitalWrite(rmb,LOW);
                break;
      case 'B': //move reverse
                digitalWrite(lmb,HIGH);
                digitalWrite(rmb,HIGH);
                digitalWrite(lmf,LOW);
                digitalWrite(rmf,LOW);
                
                break;
      case 'L': //turn right
                digitalWrite(lmf,HIGH);
                digitalWrite(lmb,LOW);
                digitalWrite(rmf,LOW);
                digitalWrite(rmb,LOW);
                break;
      case 'R': //turn left 
                digitalWrite(rmf,HIGH);
                digitalWrite(rmb,LOW);
                digitalWrite(lmf,LOW);
                digitalWrite(lmb,LOW);
                break;
      case 'S': //STOP 
                digitalWrite(rmf,LOW);
                digitalWrite(rmb,LOW);
                digitalWrite(lmf,LOW);
                digitalWrite(lmb,LOW);
                break;
    }
  }
  else
  {
     digitalWrite(rmf,LOW);
     digitalWrite(rmb,LOW);
     digitalWrite(lmf,LOW);
     digitalWrite(lmb,LOW);
  }
}

void sendit(char a)
{
  delay(500);
  switch(a)
  {
    case 'F': digitalWrite(f,HIGH);
              digitalWrite(b,LOW);
              digitalWrite(l,LOW);
              digitalWrite(r,LOW);
              break;
    case 'B': digitalWrite(f,LOW);
              digitalWrite(b,HIGH);
              digitalWrite(l,LOW);
              digitalWrite(r,LOW);
              break; 
    case 'R': digitalWrite(f,LOW);
              digitalWrite(b,LOW);
              digitalWrite(l,LOW);
              digitalWrite(r,HIGH);
              break;                  
    case 'L': digitalWrite(f,LOW);
              digitalWrite(b,LOW);
              digitalWrite(l,HIGH);
              digitalWrite(r,LOW);
              break;
    default : digitalWrite(f,LOW);
              digitalWrite(b,LOW);
              digitalWrite(l,LOW);
              digitalWrite(r,LOW);
              break;                   
  }
}
