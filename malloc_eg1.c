#include <stdio.h>
#include <stdlib.h>
int main(){
  int *p;
  p=malloc(sizeof(int));
  printf("p=%p\n",p);
  
  int i,class[6],sum=0;
  scanf("%d",&i);
  printf("i=%d, add of i=%p\n",i,&i);
  return 0;
}
