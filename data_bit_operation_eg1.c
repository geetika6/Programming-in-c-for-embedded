#include <stdio.h>
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 
int bitcount(unsigned int number) 
{ 
  unsigned int count; // the total bits set in n
    printf("\n  x =[ = %d] ,count = %d \n",number,count);
printf ("Leading text "BYTETOBINARYPATTERN, BYTETOBINARY(number));
  for (count = 0; number; number >>= 1)
  {
    count += number & 1;
    printf("\n  x =[ = %d] ,count = %d \n",number,count);
  }
  return count;
}
int countSetBits(unsigned int n)
{
  unsigned int c; // the total bits set in n
    printf("\n  x =[ = %d] ,count = %d \n",n,c);
printf ("Leading text "BYTETOBINARYPATTERN, BYTETOBINARY(n));
  for (c = 0; n; n = n & (n-1))
  {
    c++;
printf (" text "BYTETOBINARYPATTERN, BYTETOBINARY(n));
    printf("\n  x =[ = %d] ,count = %d \n",n,c);
  }
  return c;
}
int main () {
   int i=0,ret,count;
    for (i=15;i<18;i++)

    {
       count=bitcount(i) ;   
       count=countSetBits(i) ;   
    }
    
    return 0;
}
