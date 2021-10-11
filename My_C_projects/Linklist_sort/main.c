#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};
void display_linklist(struct node * head)
{
    struct node*tmp;
    tmp = head;
    while(tmp){
        printf("%d ", tmp->data);
        tmp=tmp->ptr;
    }
    printf("\n");
}
struct node* makenode(int item)
{
    struct node *to_add = (struct node*)malloc(sizeof(struct node));
    to_add->data = item;
    to_add->ptr = NULL;
    return to_add;
}

void add_linklist(int item, struct node **head, int to_display)
{
    struct node *prev;
    struct node *to_add, *tmp;
    int is_present=0;
    to_add = makenode(item);
    if(!(*head))
    {
        *head = to_add;
        tmp = NULL;
    }
    else
    {
        tmp = *head;
        prev = NULL;
        while(tmp)
        {
            if((tmp->data)<(to_add->data)){
                prev = tmp;
                tmp = tmp->ptr;
            }
            else if((tmp->data)==(to_add->data)){
                is_present = 1;
                break;
            }
            else{
                break;
            }
        }
        if(!is_present)
        {
            to_add->ptr = tmp;
        }
        if(prev)
        {
            prev->ptr = to_add;
        }
        else
        {
            *head = to_add;
        }
    }
    if (to_display){
        display_linklist(*head);
    }
    return;
}


void del_linklist(int item, struct node **head)
{
    struct node *prev;
    int deleted = 0;
    struct node *tmp;
    tmp = *head;
    if(!tmp)
    {
        printf("List empty\n");
        return;
    }
    else if(!tmp->ptr)
    {
        if(item==(tmp->data))
        {
            free(tmp);
            printf("%d\nList is empty now\n", item);
            *head = NULL;
            return;
        }
        else
        {
            printf("Number not found");
            return;
        }
    }
    prev = NULL;
    while(tmp)
    {
        if((tmp->data)==item)
        {
            if (tmp==(*head))
            {
                *head = tmp->ptr;
                free(tmp);
                printf("Number deleted\n");
                deleted =1;
                break;
            }
            printf("Number deleted\n");
            deleted = 1;
            prev->ptr = tmp->ptr;
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->ptr;
    }
    if(!deleted)
    {
        printf("Number Not Found\n");
    }
    display_linklist(*head);
    return;
}

void input_linklist(struct node**head)
{
    int do_what, item;
    while(1)
    {
        printf("If you want to add enter 1\nIf you want to delete enter 0\nElse enter anything else\n");
        scanf("%d", &do_what);
        if (do_what==1)
        {
            printf("Enter a number: ");
            scanf("%d", &item);
            add_linklist(item, head, 1);
        }
        else if(!do_what)
        {
            printf("Enter a number: ");
            scanf("%d", &item);
            del_linklist(item, head);
        }
        else
        {
            break;
        }
    }
}
void merge_list(struct node *head1, struct node *head2, struct node **head3)
{
    int item;
    struct node *to_add, *prev;
    while((head1)||(head2))
    {
        if(!head1)
        {
            item = head2->data;
            head2 = head2->ptr;
        }
        else if(!head2)
        {
            item = head1->data;
            head1 = head1->ptr;
        }
        else
        {
            if((head1->data)<=(head2->data))
            {
                item = head1->data;
                if((head1->data)==(head2->data))
                {
                    head2 = head2->ptr;
                }
                head1 = head1->ptr;
            }
            else
            {
                item = head2->data;
                head2 = head2->ptr;
            }
        }
        to_add = (struct node*)malloc(sizeof(struct node));
        to_add->data = item;
        to_add->ptr = NULL;
        if(!(*head3))
        {
            *head3 = to_add;
        }
        else
        {
            prev->ptr = to_add;
        }
        prev = to_add;
    }
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    printf("For list 1\n");
    input_linklist(&head1);
    printf("For list 2\n");
    input_linklist(&head2);
    merge_list(head1, head2, &head3);
    display_linklist(head3);
}
