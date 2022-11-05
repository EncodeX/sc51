/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏
#include "sleep.h"

void main(void) {
  char led = 1;
  char target;
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
