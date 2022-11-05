/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏

void sleep_10us(unsigned int count) {
  while (count--);
}

void main(void) {
  char led = 0;
  char temp;
  P2 = 0xFE;
  while(1) {
    if (P3_0 == 0) {
      sleep_10us(1000);
      while (P3_0 == 0);
      sleep_10us(1000);
      led++;
      if (led == 8) {
        led = 0;
      }
      temp = ~(1 << led);
      P2 = temp;
    }
    if (P3_1 == 0) {
      sleep_10us(1000);
      while (P3_1 == 0);
      sleep_10us(1000);
      if (led == 0) {
        led = 8;
      }
      led--;
      temp = ~(1 << led);
      P2 = temp;
    }
  }
}
