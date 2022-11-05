/* <!-- 引脚基础语法支持 ---- */
#include <lint.h>
/* ---- 引脚基础语法支持 ---> */
#include <reg51.h> // 8051 引脚宏
#include <stdlib.h>

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

void sleep_10us(unsigned int count) {
  while (count--);
}

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
  // 在这里消影，去除其他位影响
  sleep_10us(100);
  P0 = 0x00;
}

void dynamic_nixie(unsigned long value) {
  char index = 0;
  char target = 0;
  unsigned long temp = 0;
  while (index < 8 && value > 0) {
    temp = value - (value / 10) * 10;
    target = temp;
    static_nixie(index, target);
    index += 1;
    value = value / 10;
  }
}

void main(void) {
  unsigned long counter = 0;
  while(1) {
    dynamic_nixie(counter);
    if (P3_1 == 0) {
      sleep_10us(1000);
      while (P3_1 == 0);
      sleep_10us(1000);
      counter += 1;
    }
    if (P3_0 == 0) {
      sleep_10us(1000);
      while (P3_0 == 0);
      sleep_10us(1000);
      counter += 10;
    }
    if (P3_2 == 0) {
      sleep_10us(1000);
      while (P3_2 == 0);
      sleep_10us(1000);
      counter += 100;
    }
    if (P3_3 == 0) {
      sleep_10us(1000);
      while (P3_3 == 0);
      sleep_10us(1000);
      counter += 1000;
    }
  }
}
