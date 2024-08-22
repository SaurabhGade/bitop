#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
extern void litTobigEnd(void *buff, unsigned int n);
extern void memprint(void *ptr, int size);
unsigned int sad;
void* encode(unsigned int num){
  unsigned int byte_required;
  unsigned int buff_size  = log2(num)+1; 
  unsigned int curr = buff_size;
  unsigned char arr[32];
  unsigned char limiter = 1;
  unsigned char size;
  unsigned char val;
  unsigned char bits_used = 0;
  unsigned char rem = 0;
  unsigned char *BUFF = NULL;
  int i = 0;

  arr[i] = buff_size; i+=1;
  while(curr > 2){
    arr[i] = log2(curr)+1;
    buff_size += arr[i]+limiter;
    curr = arr[i];
    i+=1; 
  }
//  for(int j = i-1; j >= 0; j--){ printf("%d ",arr[j]);}; printf(" %d\n", num);

  byte_required = buff_size/8+1;
  void *buff = malloc(byte_required);
  assert(buff != NULL);

  i-=1;
  BUFF = (unsigned char*)buff;
  while(i > 0){
    size = arr[i];
    val = arr[i-1];
    rem = 8 - (bits_used % 8);
    if(rem >= size){
      val <<= 8-((bits_used%8)+size);
      *BUFF |= val;
    }
    else{
      val >>= ((size-rem)%8);
      *BUFF |= val;
      val = arr[i-1];
      BUFF+=1;
      val <<= (8-((size-rem)%8));
      *BUFF |= val;
    }
    bits_used += size+limiter;
    if(i == 1){
      val = 0b10000000;
      if(bits_used % 8 == 0) BUFF+=1;
      *((unsigned char*)(buff)+(int)(bits_used/8)) |= (val >> ((bits_used%8)-1));
    }
    i-=1;
  }
   
  BUFF = buff;
  unsigned int temp = num;

  
  i = log2(temp)+1;
  unsigned int bit_vec[(int)i];
  i-=1;
  val = num;
  while(i >= 0){
    bit_vec[i] = (int)(val % 2);
    val /= 2;
    i--;
  }
  i = 0; 
  BUFF += bits_used/8;
  while(1){
    rem = 8-(bits_used % 8);
    // temp /= 2;
    val = bit_vec[i];
    // val = ((temp & 1) == 0)?0:1;
    if(rem < arr[0]){
      if(val != 0){
        val <<= (rem-1)%8;
        *BUFF |= val;
      } else{}
    }
    else{
      if(val != 0){
        val <<= (rem-1)%8;
        *BUFF |= val;
      }
      else {}
    }
    bits_used+=1;
    if((bits_used%8) == 0) BUFF++;
    arr[0]-=1;
    i+=1;
    if(arr[0] == 0) break;
  }
  return buff;
}

