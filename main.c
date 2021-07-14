#define F_CPU 16000000UL
#include <util/delay.h>
 uint16_t cikti;
 uint8_t birinci_sayi;
 uint8_t ikinci_sayi;
int main(void)
{
  DDRB &= 0B00111100; //b2-b5 giris
  DDRD = 0B01111111;  //d0-d6 cıkıs
  while (1)
  {
    birinci_sayi=(PINB & 0x0c);//b2 ve b3 icin okuma
    _delay_ms(50); //debounce ı önlemek için
    ikinci_sayi=(PINB & 0x30);//b3 ve b4 icin okuma
    _delay_ms(50); //debounce ı önlemek için
    cikti=birinci_sayi * ikinci_sayi;
    switch (cikti)
    {
      case 64:
      PORTD=0b00110000;/////////////////////1
      break;
      
      case 128:
      PORTD=0b01101101;/////////////////////2
      break;
      
      case 192:
      PORTD=0b01111001;/////////////////////3
      break;
      
      case 256:
      PORTD=0b00110011;/////////////////////4
      break;
       
      case 384:
      PORTD=0b01011111;/////////////////////6
      break;
      
      case 576:
      PORTD=0b1111011;/////////////////////9
      break;
      
      default:
      PORTD=0b11111110;////////////////////0

    }
  }
  
}
