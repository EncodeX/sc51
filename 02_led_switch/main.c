/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏

void main(void) {
  while(1) {
    P2_0 = 0;
  }
}
