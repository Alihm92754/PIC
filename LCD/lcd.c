#include<pic.h>

__CONFIG(0x3f72);

#define RS RE0
#define RW RE1
#define EN RE2
#define DATA PORTD
#define DATADIR TRISD
#define CNTRLDIR TRISE

void lcdinit(void); //LCD initialization
void lcdclr(void); //Clear the LCD
void lcdcommand(unsigned char); //Command MODE
void lcddata(unsigned char); //Character MODE
void delayms(unsigned int); //DELAY

void delayms(unsigned int ms)
{
  int cnt;
  while(ms>0){
    ms--;
    for(cnt=0;cnt<220;cnt++);
  }
}

void lcdcommand(unsigned char cmd)
{
  RS = 0;
  RW = 0;
  EN = 1;
  DATA = cmd;
  EN = 0;
  delayms(5);
}

void lcddata(unsigned char characterdata)
{
  RS = 1;
  RW = 0;
  EN = 1;
  DATA = characterdata;
  EN = 0;
  delayms(5);
}

void lcdclr(void)
{
  lcdcommand(0x01);
  delayms(5);
}

void lcdinit()
{
  int i;
  unsigned char command[] = {0x38,0x0c,0x06,0x01};
  TRISD = 0x00;
  TRISE = 0x00;
  delayms(50);
  for(i=0;i<4;i++){
    lcdcommand(command[i]);
  }
  delayms(500);
}

void main()
{
  int i;
  unsigned char firstline[] = {" PIC ESD CLASS"};
  unsigned char secondline[] = {" 16x2 LCD DEMO"};

  delayms(500);
  lcdinit();
  delayms(500);

  while(1){
    lcdclr();
    lcdcommand(0x80);
    for(i=0;i<16;i++);
    {
      lcddata(firstline[i]);
      delayms(50);
    }

    lcdcommand(0xc0);
    for(i=0;i<16;i++);
    {
      lcddata(secondline[i]);
      delayms(50);
    }

    delayms(500);
  }
}