/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏

void sleep_10us(unsigned int count) {
  while (count--);
}

void main(void) {
  char led = 1;
  char target;
  P2 = 0xFE;
  while(1) {
    if (led == 8) {
      led = 0;
    }
    target = ~(1 << led);
    led++;
    P2 = target;
    sleep_10us(5000);
  }
}
