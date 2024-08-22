#include<stdio.h>

void memprint(void *ptr, unsigned int nmemb){

  unsigned char *p = (unsigned char*)ptr;
  unsigned char k; 
  int i;
  for (i=0; i<nmemb; i++) {
    k = 0b10000000;
    while(k >= 1){
      (*(p+i)&k)?printf("%d",1):printf("%d",0);
      k = (k >> 1);
    }
    printf(" ");
  }
  printf("\n");
  return;
}
