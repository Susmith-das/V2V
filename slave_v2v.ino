#define lmf 13 //left motors forward
#define lmb 12 //left motors reverse
#define rmf 11 //right motors forward
#define rmb 10 //right motors reverse
#define f 9 //decoder data
#define bk 8 //decoder data
#define l 7 //decoder data
#define r 6 //decoder data

int a,b,c,d;

void setup()
{
pinMode(lmf,OUTPUT);  
pinMode(lmb,OUTPUT);   
pinMode(rmf,OUTPUT);   
pinMode(rmb,OUTPUT);
pinMode(f,INPUT);
pinMode(bk,INPUT);
pinMode(l,INPUT);
pinMode(r,INPUT);   
Serial.begin(9600);
}
 
void loop()
{
  a=digitalRead(f);
  b=digitalRead(bk);
  c=digitalRead(l);
  d=digitalRead(r);
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.print(",");
  Serial.print(c);
  Serial.print(",");
  Serial.println(d);
  if(a==1&&b==0&&c==0&&d==0)
    {
     digitalWrite(lmf,HIGH);
     digitalWrite(rmf,HIGH);
     digitalWrite(lmb,LOW);
     digitalWrite(rmb,LOW);
    }
   else if(a==0&&b==1&&c==0&&d==0) 
    {
      digitalWrite(lmb,HIGH);
      digitalWrite(rmb,HIGH);
      digitalWrite(lmf,LOW);
      digitalWrite(rmf,LOW);
    }
   else if(a==0&&b==0&&c==1&&d==0)  
    {
       digitalWrite(rmf,HIGH);
       digitalWrite(rmb,LOW);
       digitalWrite(lmf,LOW);
       digitalWrite(lmb,LOW);
    } 
   else if(a==0&&b==0&&c==0&&d==1) 
    {
       digitalWrite(lmf,HIGH);
       digitalWrite(lmb,LOW);
       digitalWrite(rmf,LOW);
       digitalWrite(rmb,LOW);         
    }
   else
    {
     digitalWrite(rmf,LOW);
     digitalWrite(rmb,LOW);
     digitalWrite(lmf,LOW);
     digitalWrite(lmb,LOW);
    }
}
