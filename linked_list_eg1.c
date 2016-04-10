#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct test_struct
{
    int val;
    struct test_struct *next;
};
struct test_struct *ptr;
struct test_struct *head = NULL;
struct test_struct *curr = NULL;

struct test_struct* create_list(int val)
{
    printf("\n creating list with headnode= %d ",val);
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    printf("and address of headnode =%p \n",ptr);
    return ptr;
}

void print_list (void)
{
   struct test_struct *ptr=head;
   printf("-----Starting link list-------\n");
   while (ptr!=NULL)
   {
       printf("\nvalue of node=%d, add of next node=%p \n",ptr->val,ptr->next);
       ptr=ptr->next;
   } 
   printf("-----Ending link list-------\n");
}
struct test_struct* extend_list(int val,bool insert_at_end)
{
    if(NULL == head)
    {
	return(create_list(val));
    }
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    if(!insert_at_end)
    {
        printf("Adding node in beginning \n");
	ptr->next=head;
        head=ptr;		
    }
    else
    {
        printf("Adding node in end \n");
	curr->next=ptr;
        curr=ptr;
    }
    return ptr; 
   
} 
struct test_struct* search_in_list(int val, struct test_struct **prev)
{
    struct test_struct *ptr = head;
    struct test_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",val);

    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

int delete_from_list(int val)
{
    struct test_struct *prev = NULL;
    struct test_struct *del = NULL;

    printf("\n Deleting value [%d] from list\n",val);

    del = search_in_list(val,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

int main () {
   int i=0,ret;
    struct test_struct *ptr = NULL;
    print_list();
    for (i=5;i<10;i++)
    {
       extend_list(i,true) ;   
    }
    print_list();
    for (i=15;i<20;i++)
    {
       extend_list(i,false) ;   
    }
    print_list();
    for(i = 1; i<10; i += 4)
    {
        ptr = search_in_list(i, NULL);
        if(NULL == ptr)
        {
            printf("\n Search [val = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n Search passed [val = %d]\n",ptr->val);
        }

        print_list();
 ret = delete_from_list(i);
        if(ret != 0)
        {
            printf("\n delete [val = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n delete [val = %d]  passed \n",i);
        }

        print_list();
    }
    return 0;
}
