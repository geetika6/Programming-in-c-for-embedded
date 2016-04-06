//Program to find the sum of six numbers with arrays and pointers.
#include <stdio.h>
int main(){
  int array_no_size[]={1,1,2,3};
  int i,class[6],sum=0;
  char arrays[]="hello          n ";
   char *pointers= arrays;
   printf("%s\n",pointers);
  printf("Enter 6 numbers:\n");
  for(i=0;i<8;++i)
  {
      scanf("%d",(class+i)); // (class+i) is equivalent to &class[i]
      printf("class=%p,%p\n",class,&class[i]);
      printf("array_no_size=%d,%p\n",array_no_size[i],&array_no_size[i]);
      sum += *(class+i); // *(class+i) is equivalent to class[i]
  }
  printf("Sum=%d\n",sum);
   scanf("%[^\n]s",pointers); //delimiter is \n
   printf("%s\n",pointers);
   scanf("%[^ ]s",pointers); //delimiter is space
   printf("%s\n",pointers);
  return 0;
}
