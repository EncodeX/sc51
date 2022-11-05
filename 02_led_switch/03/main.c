/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏

void sleep_10us(unsigned int count) {
  while (count--);
}

void main(void) {
  char temp;
  P2 = 0xFF;
  while(1) {
    if (P3_1 == 0) {
      sleep_10us(1000);
      while (P3_1 == 0);
      sleep_10us(1000);
      temp = ~P2;
      temp ++;
      P2 = ~temp;
    }
  }
}
