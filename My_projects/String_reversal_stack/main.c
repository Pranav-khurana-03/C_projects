#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node * ptr;
};

void push(char i, struct node **head)
{
    struct node * tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp ->data = i;
    tmp ->ptr = *head;
    *head = tmp;
}
char pop(struct node **head)
{
    char item;
    if (!(*head))
    {
        exit(0);
    }
    item = (*head) -> data;
    struct node *q = *head;
    *head = (*head)->ptr;
    free(q);
    return item;
}

int main()
{
    struct node* head;
    int size,i;
    char a, result;
    while(1)
    {
        scanf("%c", &a);
        if(a!='\n')
            push(a, &head);
        else
            break;
    }
    while(head->ptr)
    {
        result = pop(&head);
        printf("%c", result);
    }
}
