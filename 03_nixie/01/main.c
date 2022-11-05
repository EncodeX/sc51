/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏

unsigned char nixie_map[] = {
  // table   dp g f e d c b a
  0x3F, // 0  0 0 1 1 1 1 1 1
  0x06, // 1  0 0 0 0 0 1 1 0
  0x5B, // 2  0 1 0 1 1 0 1 1
  0x4F, // 3  0 1 0 0 1 1 1 1
  0x66, // 4  0 1 1 0 0 1 1 0
  0x6D, // 5  0 1 1 0 1 1 0 1
  0x7D, // 6  0 1 1 1 1 1 0 1
  0x07, // 7  0 0 0 0 0 1 1 1
  0x7F, // 8  0 1 1 1 1 1 1 1
  0x6F, // 9  0 1 1 0 1 1 1 1
};

unsigned char reverse_bits(unsigned char value) {
  unsigned char result = 0;
  while (value > 0) {
    result <<= 1;
    if (value & 1 == 1) {
      result ^= 1;
    }
    value >>= 1;
  }
  return result;
}

void static_nixie(unsigned char target, unsigned char value) {
  char temp = target << 2; // 00000abc => 000abc00
  P2 = P2 & 0xE3 | temp;
  P0 = nixie_map[value];
}

void sleep_10us(unsigned int count) {
  while (count--);
}

void main(void) {
  char target = 0;
  char counter = 0;
  while(1) {
    static_nixie(target, counter);
    target++;
    counter++;
    if (target == 8) {
      target = 0;
    }
    if (counter == 10) {
      counter = 0;
    }
    sleep_10us(100000);
  }
}
