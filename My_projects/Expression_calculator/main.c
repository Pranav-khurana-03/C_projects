#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct compute_stack
{
    double data;
    struct compute_stack*ptr;
};


double ascii_to_float(char*str)
{
    int sign =1;
    int size = 0;
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='.')
        {
            break;
        }
        if((str[i]!='+')&&(str[i]!='-'))
        {
            size++;
        }
        i++;
    }
    double multiplier = pow(10,size-1);
    double result = 0;
    i=0;
    if(str[0]=='-')
    {
        sign = 0;
        i=1;
    }
    else if(str[0]=='+')
    {
        i=1;
    }
    while(str[i]!='\0')
    {
        if(((str[i]>='0')&&(str[i]<='9'))||(str[i]=='.'))
        {
            if((str[i]=='.')){
                i++;
            }
            if(sign)
            {
                result = result + multiplier*(str[i]-'0');
            }
            else
            {
                result = result - multiplier*(str[i]-'0');
            }
            multiplier = multiplier/10;
        }
        i++;
    }
    return result;
}

double convert(char*num, int start, int end)
{
    int size = end-start;
    char*new_num;
    new_num = (char*)malloc(sizeof(char)*size+1); //Memory leak
    memset(new_num, '\0', size+1);
    int i=0;
    while(i<size)
    {
        new_num[i]=num[start];
        start++;
        i++;
    }
    double result = ascii_to_float(new_num);
    return result;
}


struct stack
{
    char data;
    struct stack*ptr;
};

void push(char i, struct stack **head)
{
    struct stack * tmp;
    tmp = (struct stack*)malloc(sizeof(struct stack));
    tmp->data = i;
    tmp ->ptr = *head;
    *head = tmp;
}
char pop(struct stack **head)
{
    char item;
    if (!(*head))
    {
        exit(0);
    }
    item = (*head)->data;
    struct stack *q = *head;
    *head = (*head)->ptr;
    free(q);
    return item;
}

void push_compute(double num, struct compute_stack **head)
{
    struct compute_stack * tmp;
    tmp = (struct compute_stack*)malloc(sizeof(struct compute_stack));
    tmp->data = num;
    tmp ->ptr = *head;
    *head = tmp;
}
double pop_compute(struct compute_stack **head)
{
    double item;
    if (!(*head))
    {
        exit(0);
    }
    item = (*head)->data;
    struct compute_stack *q = *head;
    *head = (*head)->ptr;
    free(q);
    return item;
}

void postfix_eval(char*postfix, struct compute_stack**compute_stack_head)
{
    int i=0;
    int start, end;
    double num1, num2;
    int n1,n2;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            start = i;
            end = start;
            while(isdigit(postfix[i]))
            {
                end++;
                i++;
            }
            i--;
            push_compute(convert(postfix, start, end), compute_stack_head);
        }
        else
        {
            switch(postfix[i])
            {
                case '+':
                    num2 = pop_compute(compute_stack_head);
                    num1 = pop_compute(compute_stack_head);
                    push_compute((num1+num2), compute_stack_head);
                    break;
                case '-' :
                    num2 = pop_compute(compute_stack_head);
                    num1 = pop_compute(compute_stack_head);
                    push_compute((num1-num2), compute_stack_head);
                    break;
                case '/':
                    num2 = pop_compute(compute_stack_head);
                    num1 = pop_compute(compute_stack_head);
                    push_compute((num1/num2), compute_stack_head);
                    break;
                case '*':
                    num2 = pop_compute(compute_stack_head);
                    num1 = pop_compute(compute_stack_head);
                    push_compute((num1*num2), compute_stack_head);
                    break;
                case '%':
                    n2 = pop_compute(compute_stack_head);
                    n1 = pop_compute(compute_stack_head);
                    push_compute((n1%n2), compute_stack_head);
                    break;
                case '^':
                    num2 = pop_compute(compute_stack_head);
                    num1 = pop_compute(compute_stack_head);
                    push_compute(pow(num1, num2), compute_stack_head);
                    break;
            }
        }
        i++;
    }
}

void operator_place(char*exp, char op1, struct stack**stack_head, int*index)
{
    if(!(*stack_head))
    {
        push(op1, stack_head);
        return;
    }
    char op2;
    switch(op1)
    {
        case '(':
            push(op1, stack_head);
            break;
        case '+':
        case'-' :
            op2 = (*stack_head)->data;
            if(op2!='(')
            {
                op2 = pop(stack_head);
                exp[(*index)] = op2;
                exp[(*index)+1] = ' ';
                (*index)++;
                operator_place(exp, op1, stack_head, index);
            }
            else
            {
                push(op1, stack_head);
            }
            break;
        case '/':
        case '*':
        case '%':
            op2 = (*stack_head)->data;
            if((op2=='+')||(op2=='-'))
            {
                push(op1, stack_head);
            }
            else
            {
                if(op2!='(')
                {
                    op2 = pop(stack_head);
                    exp[(*index)] = op2;
                    push(op1, stack_head);
                    exp[(*index)+1] = ' ';
                    (*index)++;
                }
                else
                {
                    push(op1, stack_head);
                }
            }
            break;
        case '^':
            push(op1, stack_head);
            break;
        case ')':
            while(((*stack_head)->data)!='(')
            {
                op2 = pop(stack_head);
                exp[(*index)] = op2;
                exp[(*index)+1] = ' ';
                (*index)++;
            }
            pop(stack_head);
            break;
        default:
            printf("YOU ENTERED AN INVALID OPERATOR!");
            exit(1);
    }
}

void postfix_convert(char*exp, struct stack**stack_head, char*postfix)
{
    static int i;
    static int j;
    char op1;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            while(isdigit(exp[i])||(exp[i]=='.'))
            {
                postfix[j] = exp[i];
                i++;
                postfix[j+1] = ' ';
                j++;
            }
        }
        else
        {
            op1 = exp[i];
            operator_place(postfix, op1, stack_head, &j);
            i++;
            postfix[j+1] = ' ';
            j++;
        }
    }
    while((*stack_head))
    {
        op1 = pop(stack_head);
        postfix[j] = op1;
        j++;
    }
    postfix[j+1] = '\0';
}

int main()
{
    struct stack* stack_head= NULL;
    struct compute_stack* compute_stack_head = NULL;
    char infix[1024];
    char postfix[1024];
    memset(infix, 0, 1024);
    memset(postfix, 0, 1024);
    gets(infix);
    postfix_convert(infix, &stack_head, postfix);
    printf("%s", postfix);
    printf("\n");
    postfix_eval(postfix, &compute_stack_head);
    printf("%f", compute_stack_head->data);
}
