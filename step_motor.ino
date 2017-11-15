int a2=500;
int s=0;
int S=0;
int Z;
int i=1;
int last_z=1;
volatile int ab=3;
void setup()
{
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  attachInterrupt(0,A,CHANGE);
  //attachInterrupt(1,B,CHANGE);
}
void loop() 
{
  if(S>0)
  {
    step_motor(S,Z);
    S=0;
  }
    
  
 
 
}
//////////////////////////////////////////////////////
void A()
{
  S=1;
  int Z=0;
  ab=ab+1;
  
}
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
void step_motor(int s,int z)
{
  if(last_z!=z)
  {
    i=1-i;
  }
  int j=0;
  int t=16;
  int n=1-z*2;
  int a1;
  int b1;
  int b2;
  for(s;s>0;s--)
  {
    switch(j)
    {
      case 0:
      t=t/2;
      if(t<=2)
      {
        j=1;
      }
      break;
      case 1:
      if(s<=3)
      {
        t=t*2;
      }
      break;
    }
    switch(i)
   {
    case 0:
    a1=a2-1;
    b1=a1%4;
    digitalWrite(b1+4,1-z);
    i=1-i;
    break;
    case 1:
    a2=a2-n*z;
    b2=a2%4;
    digitalWrite(b2+4,z);
    a2=a2-n-z;
    i=1-i;
    break;
    }
    delay(t);
    if(a2==4||a2==1000)
    {
    a2=500;
     }
  }
  last_z=z;
  
 
}


