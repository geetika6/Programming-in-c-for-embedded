#include <stdio.h>
#include <stdlib.h>
//int main(){
//  int *p, *memory, *new_memory;
//  int count=0;
//  printf("enter number=");
//  scanf("%d",&p);
//  while (*p!='0')
//  {
//    memory=malloc((count+1)*sizeof(int));
//    memory[count]=p;
//     count++;
//  }
//  free(p);
//  return 0;
//}
/* realloc example: rememb-o-matic */
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

int main ()
{
  int input,n;
  int count = 0;
  int* numbers = NULL;
  int* more_numbers = NULL;

  do {
     printf ("Enter an integer value (0 to end): ");
     scanf ("%d", &input);
     count++;

     more_numbers = (int*) realloc (numbers, count * sizeof(int));
    // more_numbers =malloc(count * sizeof(int));
    //more_numbers =(int*)malloc(count * sizeof(int));
     if (more_numbers!=NULL) {
       numbers=more_numbers;
       numbers[count-1]=input;
       printf ("value at number=%d and address of number=%p,more_number=%p \n ",input,numbers,more_numbers);
     }
     else {
       free (numbers);
       puts ("Error (re)allocating memory");
       exit (1);
     }
  } while (input!=0);

  printf ("Numbers entered: ");
  for (n=0;n<count;n++) printf ("n=%d, value=%d and address=%p \n ",n,numbers[n],&numbers[n]);
  free (numbers);

  return 0;

}
