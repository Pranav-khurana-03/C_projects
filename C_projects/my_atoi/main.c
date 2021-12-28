#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int my_atoi(char*str)
{
    int size = 0, i;
    while((str[size]>='0')&&(str[size]<='9'))
    {
        size++;
    }
    int multiplier = pow(10,size-1);
    int result = 0;
    for(i= 0;i<size;i++)
    {
        result = result + multiplier*(str[i]-'0');
        multiplier = multiplier/10;
    }
    return result;
}

double ascii_to_float(char*str, int* status)
{
    *status = 1;
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
        else
        {
            *status=0;
        }
        i++;
    }
    return result;
}

int main()
{
    char a[] = "257 haha" ;
    printf("%d", my_atoi(a));
}
