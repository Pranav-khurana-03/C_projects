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

struct node* find_middle()
{
    struct node* tmp, *tmp2;
    struct node*middle;
    tmp = head;
    tmp2 = head->ptr;
    int iteration=1,i;
    while(1)
    {
        if(!tmp2)
        {
            middle = tmp;
            break;
        }
        iteration++;
        tmp = tmp->ptr;
        if(tmp2->ptr)
        {
            tmp2 = tmp2->ptr->ptr;
        }
        else
        {
            tmp2 = tmp2->ptr;
        }
    }
    return middle;
}

int main()
{
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
    struct node*middle = find_middle();
    printf("%d", middle->data);
}
