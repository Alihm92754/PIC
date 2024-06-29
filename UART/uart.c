#include<pic.h>
#include<stdio.h>

__CONFIG(0x3f72);

#define Buzz RB0
#define Relay1 RB1
#define Relay2 RB2

#define FOSC 10000
#define BAUD_RATE 9.6
#define BAUD_VAL (char)(FOSC/(16*BAUD_RATE))-1;

void delayms(unsigned int);

void delayms(unsigned int ms)
{
int cnt;
while(ms>0){
ms--;
for(cnt=0;cnt<220;cnt++);
}
}

void putch(unsigned char data)
{
while(TXIF == 0);
TXREG = data;
}

void main()
{
unsigned char receivechar;

TRISB = 0x00;
PORTB = 0x04;
TRISC = 0xC0;
TXSTA = 0x24;
SPBRG = BAUD_VAL;
RCSTA = 0x90;
while(1){
while(RCIF == 0)
RCIF = 0;
receivechar = RCREG;
printf("%c",receivechar);
switch(receivechar){
  case '1':
   Buzz=1;
   Break;
  case '2':
   Buzz=0;
   Break;
  case '3':
   Relay1=1;
   Break;
  case '4':
   Relay1=0;
   Break;
  case '5':
   Relay2=1;
   Break;
  case '6':
   Relay2=0;
   Break;
}

}
}
