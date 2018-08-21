
 //*timer 1 and 3 configure for pins 9 10 and 5*//
 void pwm5_9_10configure(int mode)
 {
 // TCCR1A configuration
 //  00 : Channel A disabled D9
 //  00 : Channel B disabled D10
 //  00 : Channel C disabled D11
 //  01 : Fast PWM 8 bit
 TCCR1A=1;
 TCCR3A=1;

 // TCCR1B configuration
 // Clock mode and Fast PWM 8 bit
 TCCR1B=mode|0x08;  
 TCCR3B=mode|0x08;

// TCCR1C configuration
TCCR1C=0;
TCCR3C=0;
}
//*timer 4 configuring for pin 6*//
void pwm6configure(int mode)
{
// TCCR4A configuration
TCCR4A=0;

// TCCR4B configuration
TCCR4B=mode;

// TCCR4C configuration
TCCR4C=0;

// TCCR4D configuration
TCCR4D=0;

// PLL Configuration
// Use 96MHz / 1.5 = 64MHz
PLLFRQ=(PLLFRQ&0xCF)|0x20;

// Terminal count for Timer 4 PWM
OCR4C=255;
}
void pwmSet5(int value)
{
OCR3A=value;   // Set PWM value
TCCR3A|=0x80;  // Activate channel
}
void pwmSet9(int value)
{
OCR1A=value;   // Set PWM value
TCCR1A|=0x80;  // Activate channel
}
void pwmSet10(int value)
{
OCR1B=value;   // Set PWM value
TCCR1A|=0x20;  // Activate channel
}
void pwmSet6(int value)
{
OCR4D=value;   // Set PWM value
TCCR4C|=0x09;  // Activate channel
}

void setup() 
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pwm5_9_10configure(1);//16M/256/1=62500Hz
  pwm6configure(4);//64M/256/4=62500Hz
}

void loop() 
{
  pwmSet5(30);
  pwmSet6(30);
  pwmSet9(30);
  pwmSet10(30);

}
