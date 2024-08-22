#include "../include/bitop.h"
#define FROM_MSB(byte_count, counter) (byte_count)*(8)-(counter+1) 
void* encode(unsigned long num){
  unsigned int bit_count = 0;
  unsigned int byte_count = 0;
  unsigned short limiter = 1;
  unsigned int counter = 0;
  unsigned long t = num;
  void *buff; 
  unsigned char arr[32];
  unsigned char size, val;
  int i = 0;
  while(t > 2){
    bit_count += (log2(t)+1)+limiter;
    t = log2(t)+1;
    arr[i] = t;
    i++;
    printf("%ld ",t);
  }
  byte_count = bit_count/8+1;
  buff = malloc(byte_count);
  i-=1; 
  //2 3 7 65
  //65 7 3 2
  while(i > 0){
    size = arr[i];
    val = arr[i-1];
    val <<= 8-size;
    for(int j = 7; j >= 8-size; j--){
      (is_bit_set(&val, 1, j))? 
        set_bit(buff, byte_count, FROM_MSB(byte_count, counter)): 
        clr_bit(buff, byte_count, FROM_MSB(byte_count, counter));
      counter+=1;
    }
    (i == 1)? 
      set_bit(buff, byte_count, FROM_MSB(byte_count, counter)):
      clr_bit(buff, byte_count, FROM_MSB(byte_count, counter));
    counter+=1;
    i-=1;
  }

  return buff;
}
