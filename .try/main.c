#include<math.h>
#include<stdlib.h>
#include<stdio.h>
extern void* encode(int num);
extern void decode(void *buff);
extern void memprint(void *ptr, int size); 

int main(){

  unsigned long val = pow(2, 11)-1;
  //unsigned long val = 31;
  if(1){
    void *buff= encode(val);
    decode(buff);
  }
  else{
    for(int i = 0 ; i < 31; i++){
      unsigned long val = pow(2, i)-1;
      void *buff = encode(val);
      decode(buff);
      printf("\n");
    }
  }
  return 0;
}
