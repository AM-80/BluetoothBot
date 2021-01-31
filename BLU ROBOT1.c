/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 24/02/2018
Author  : WWW.PARANDCO.COM
Company : PARAND
Comments: 


Chip type               : ATmega32A
Program type            : Application
AVR Core Clock frequency: 8/000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32a.h>
#include <stdio.h>
// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
// Standard Input/Output functions

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Place your code here

}

char i,a,c,z[20];


// Declare your global variables here

void main(void)
{
// Declare your local variables here
c=0;
// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x0A;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=Out Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=0 State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x08;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0xFF;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 7/813 kHz
// Mode: Fast PWM top=0xFF
// OC0 output: Non-Inverted PWM
TCCR0=0x6D;
TCNT0=0x00;
OCR0=300;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x01;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 38400
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x06;
UBRRH=0x00;
UBRRL=0x0C;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 4
// RD - PORTA Bit 5
// EN - PORTA Bit 6
// D4 - PORTB Bit 4
// D5 - PORTB Bit 5
// D6 - PORTB Bit 6
// D7 - PORTB Bit 7
// Characters/line: 16
lcd_init(16);

// Global enable interrupts
#asm("sei")

while (1)
{    if(c==0)
{
lcd_gotoxy(0,0);
lcd_puts("WAITING");
for(a=8;a<=11;a++)
{
lcd_gotoxy(0,a);
lcd_puts(".");
delay_ms(800);
}
c++;
lcd_clear();
lcd_gotoxy(0,0);
lcd_puts("READY");
}


      i=getchar();
      switch (i){
      case 'd':{printf("Direct\r\n");PORTA.1=0;PORTA.3=0;PORTC.4=0;PORTC.6=0;delay_ms(100);PORTA.1=1;PORTA.3=0;PORTC.4=1;PORTC.6=0;
      lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      lcd_gotoxy(5,1);
      lcd_puts("DIRECT");
      ;}
      break;
      case 'b':{printf("Back\r\n");PORTA.1=0;PORTA.3=0;PORTC.4=0;PORTC.6=0;delay_ms(100);PORTA.1=0;PORTA.3=1;PORTC.4=0;PORTC.6=1;
        lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      lcd_gotoxy(6,1);
      lcd_puts("BACK");
      ;}
      break;
      case 'l':{printf("Left\r\n");PORTA.1=0;PORTA.3=0;PORTC.4=0;PORTC.6=0;delay_ms(100);PORTA.1=0;PORTA.3=1;PORTC.4=1;PORTC.6=0;
        lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      lcd_gotoxy(3,1);
      lcd_puts("TURN LEFT");
      ;}
      break;
      case 'r':{printf("Right\r\n");PORTA.1=0;PORTA.3=0;PORTC.4=0;PORTC.6=0;delay_ms(100);PORTA.1=1;PORTA.3=0;PORTC.4=0;PORTC.6=1;
        lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      lcd_gotoxy(3,1);
      lcd_puts("TURN RIGHT");
      ;}
      break;
      case '+':{printf("Speed High\r\n");if(OCR0<=240) OCR0=OCR0+10; 
      lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      }
      break;
      case '-':{printf("Speed Low\r\n");if(OCR0>=20) OCR0=OCR0-10;
      lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      }
      break;
      case 'O':{printf("Light On\r\n");PORTC.0=1;PORTC.1=0;}
      break; 
      case 'o':{printf("Light Off\r\n");PORTC.0=0;PORTC.1=0;}
      break;     
      case 's' :{printf("Stop\r\n");PORTA.1=0;PORTA.3=0;PORTC.4=0;PORTC.6=0;
        lcd_clear();
      sprintf(z,"PWM=%d",OCR0);
      lcd_gotoxy(4,0);
      lcd_puts(z);
      lcd_gotoxy(6,1);
      lcd_puts("STOP");
      }
      break; 
      case 'h' :{printf("Horn is Ring\r\n");PORTD.3=1;PORTD.4=0;delay_ms(1000);
      PORTD.3=0;PORTD.4=0; 
      PORTA.1=0;PORTA.3=0;PORTC.4=0;PORTC.6=0;
      }
      


      }  
      }

      }    
     
