#include<stdio.h>

int main()
{
	char *str;
	while(1)
	{
		scanf("%s", str);
		int i = 0;
		int count = 0;
		int balanced = 1;
		while(str[i]!='\0')
		{
			if(str[i]=='(')
				count++;
			else if(count < 0)
				break;
			else
				count--;
			i++;
		}
	}
}
