#include "../include/bitop.h"
#include <stdbool.h>
unsigned long decode(void *bit_vec){
  unsigned long ans = 0x0;
  unsigned int counter = 0x0;
  void *buff = bit_vec;
  bool flag = true;
  unsigned char size = 0x2;     // Initial size starts with two.
  unsigned char val = 0x0;
  while(flag){
    val = 0x0;
    printf("size = %d",size);
    while(size){
      (is_bit_set(buff, 0xb, FROM_MSB(0xb, counter)))?
        set_bit(&val, 1, size-1):
        clr_bit(&val, 1, size-1);
      counter++;
      size--;
    }
    printf(" val = %d\n",val);
    size = val;

    flag = is_bit_set(buff, 0xb, FROM_MSB(0xb, counter))?
      false:
      true;
    counter+=1;
  }
  while(val > 0){
    ans += is_bit_set(buff, 0xb, FROM_MSB(0xb, counter))?
      pow(2, val-1): 0;
    counter+=1;
    val -=1;
  }
  return ans;
}
