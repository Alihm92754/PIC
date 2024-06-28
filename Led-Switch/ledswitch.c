#include<pic.h>

__CONFIG(0x3f72);

void delayms(unsigned int);
void delayms(unsigned int ms)
{
int cnt;
while(ms>0){
ms--;
for(cnt=0;cnt<220;cnt++);
}
}

void main()
{
delayms(10);
TRSIB = 0xff;
TRISC = 0x00;
PORTC = 0x00;
delayms(10);
while(1){
PORTC = PORTB;
delayms(500);
}
}