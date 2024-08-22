#include<stdio.h>
#include<math.h>
#include "../include/bitop.h"

int main(){
  void * buff = encode(0b111111111111111111111111111111111111111111111111111111111111111);
  memprint(buff, 10); 
  printf("EVERYTHING WORKING FINE\n");
  return 0;
}
