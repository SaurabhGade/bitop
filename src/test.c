#include<stdio.h>
#include<math.h>
#include "../include/bitop.h"

int main(){
  void * buff = encode(0xfffffffffffff);
  memprint(buff, 2);
  unsigned long k = decode(buff);
  printf("%lX\n",k);
 // memprint(buff, 10); 
//  printf("EVERYTHING WORKING FINE\n");
  /*
  unsigned long k = 888;
  memprint(&k , 8);
  rv_endiannes(&k, 8);
  memprint(&k, 8);
  */
  return 0;
}
