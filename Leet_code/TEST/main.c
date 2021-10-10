#include <stdio.h>

int main() {
    int t;
	scanf("%d", &t);
	for(int i =0;i<t;i++)
	{
	    int upper = 0, lower = 0, num= 0;
	    int print = 0;
	    char tmp, garb;
		scanf("%c", &garb);
	    scanf("%c", &tmp);
	    while(tmp!='\n')
	    {
	        if((tmp>='A')&&(tmp<='Z'))
	        {
	            upper = 1;
	            scanf("%c", &tmp);
	        }
	        else if((tmp>='a')&&(tmp<='z'))
	        {
	            lower = 1;
	            scanf("%c", &tmp);
	        }
	        else if((tmp>='0')&&(tmp<='9'))
	        {
	            num = 1;
	            scanf("%c", &tmp);
	        }
	        if((num)&&(lower)&&(upper))
	        {
	            print = 1;
	            break;
	        }
	    }
	    if(print)
	    {
	        printf("YES\n");
	    }
	    else
	    {
	        printf("NO\n");
	    }
	}
	return 0;
}