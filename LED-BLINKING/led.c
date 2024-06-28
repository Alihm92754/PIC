#include<pic.h>
__CONFIG(0x3f72);
void delayms(unsigned int);
void main()
{
  TRISB = 0x00;
  while(1)
  {
    PORTB = 0xFF;
    delayms(500);
    PORTB = 0;
    delayms(500);
  }
}

void delayms(unsigned int ms)
{
int delaycnt;
while(ms>0)
{
ms--;
for(delaycnt=0;delaycnt<220;delaycnt++);
}
}