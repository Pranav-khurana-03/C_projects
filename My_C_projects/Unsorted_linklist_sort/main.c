#include <stdio.h>
#include <stdlib.h>

struct node *head=NULL;

struct node
{
    int data;
    struct node *ptr;
};
void add_node(int item)
{
    struct node *tmp;
    struct node *to_add;
    to_add = (struct node*)malloc(sizeof(struct node));
    if(!head)
    {
        to_add->data = item;
        to_add->ptr = NULL;
        head = to_add;
        return;
    }
    tmp = head;
    while(tmp)
    {
        if(!(tmp->ptr))
        {
            tmp->ptr = to_add;
            to_add->data = item;
            to_add->ptr = NULL;
        }
        tmp = tmp->ptr;
    }
}

void del_node(int item)
{
    struct node*tmp;
    struct node*prev=NULL;
    if(!head)
    {
        printf("List empty\n");
        return;
    }
    tmp =head;
    while(tmp)
    {
        if((tmp->data)==item)
        {
            printf("Number deleted\n");
            if(prev)
            {
                prev->ptr = tmp->ptr;
                free(tmp);
                return;
            }
            head = tmp->ptr;
            free(tmp);
            return;
        }
        prev=tmp;
        tmp = tmp->ptr;
    }
    printf("Number not found\n");
}

void display_linklist()
{
    struct node*tmp;
    tmp = head;
    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->ptr;
    }
    printf("\n");
}

void sort_linklist()
{
    struct node* tmp, *tmp2;
    struct node* prev1=NULL, *prev2=NULL;
    struct node* temp_ptr;
    int is_first;
    tmp = head;
    while(tmp)
    {
        tmp2 = tmp->ptr;
        prev2 = tmp;
        is_first=1;
        while(tmp2)
        {
            if((tmp->data)>(tmp2->data))
            {
                if(is_first)
                {
                    temp_ptr = tmp2->ptr;
                    tmp2->ptr = tmp;
                    tmp->ptr = temp_ptr;
                }
                else
                {
                    temp_ptr = tmp->ptr;
                    tmp->ptr= tmp2->ptr;
                    tmp2->ptr = temp_ptr;
                    prev2->ptr = tmp;
                }
                temp_ptr = tmp2;
                tmp2 = tmp;
                tmp = temp_ptr;
                if(prev1)
                {
                    prev1->ptr= tmp;
                }
                else
                {
                    head = tmp;
                }
            }
            is_first = 0;
            prev2 = tmp2;
            tmp2 = tmp2->ptr;
        }
        prev1 = tmp;
        tmp = tmp->ptr;
    }
}

int main()
{
    /*int arr[] = {9,4,2,0,8,1,9,-1,-4,3};
    int i,j, small, temp;
    int size = (sizeof(arr))/4;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<=arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }*/
    int item;
    int do_what=1;
    while(do_what)
    {
        printf("To add: 1\nTo delete: -1\nTo exit: 0\n");
        scanf("%d", &do_what);
        if(do_what)
        {
            printf("Enter a number: ");
            scanf("%d", &item);
            if(do_what==1)
            {
                add_node(item);
            }
            else
            {
                del_node(item);
            }
        }
        display_linklist();
    }
    sort_linklist();
    display_linklist();
}
