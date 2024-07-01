#include<htc.h>
#include<pic.h>

#define _XTAL_FREQ 20000000

void rundutycycle(unsigned int x);

#define S1 RD0
#define S2 RD1
#define S3 RD2
#define S4 RD3
#define S5 RD4
#define S6 RD5
#define S7 RD6

void main()
{
  TRISD = 0xFF;   //PORTD as Input
  TRISC2 = 0;     //Make CCP1 as Pin Output
  CCP1CON = 0x0C; //Configure CCP1 Module In PWM Mode
  PR2 = 0xFF;
  rundutycycle(512);     
}

void rundutycycle(unsigned int dutycycle)
{
  T2CON = 0x01;  //Set PRESCALER to be 4
  T2CON |= 0x04; //Enable the TIMER2, TIMER2 ON=1
  while(1){
    CCPR1L = dutycycle >> 2;
    CCP1CON &= 0xCF;
    CCP1CON |= (0x30 & (dutycycle << 4));
    if(S1 == 1){dutycycle=172;} 
    if(S2 == 1){dutycycle=342;} 
    if(S3 == 1){dutycycle=512;}
    if(S4 == 1){dutycycle=686;}
    if(S5 == 1){dutycycle=858;}
    if(S6 == 1){dutycycle=1020;}
    if(S7 == 1){dutycycle=0;}
    dutycycle = dutycycle;
  }
}
