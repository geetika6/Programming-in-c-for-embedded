#include <stdio.h>
#include <stdlib.h>
struct person
{
char name[20];
int age;
int dob;
};

int main()
{
struct person identity;
struct person *ptr;
ptr=&identity;	
ptr->age=10;
printf ("%d\n",ptr->age); 
  return 0;
}
