/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏

void main(void) {
  while(1) {
    if (P3_1 == 0) {
      P2_0 = 0;
    } else {
      P2_0 = 1;
    }
  }
}
