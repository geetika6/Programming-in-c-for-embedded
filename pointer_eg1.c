#include <stdio.h>

void main()
{

int p;
int r;
int *q=&p;
scanf("%d",&p);
printf("value of p=%d\n",p);
printf("value of p=%p\n",&p);
printf("value of p=%d\n",*q);
printf("value of p=%p\n",q);

}
