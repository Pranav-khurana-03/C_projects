#include<stdio.h>
#include<string.h>

int palindrome(char* str, int lb, int ub)
{
	int i;
	int size = ub - lb;
	if (size<=0)
	{
		return 1;
	}
	if (str[ub] == str[lb])
	{
		if (palindrome(str, lb+1, ub - 1))
		{
			for (i = lb;i <= ub;i++)
			{
				printf("%c", str[i]);
			}
			printf("\n");
			return 1;
		}
	}
	int temp = ub;
	ub = ub - 1;
	lb = lb - 1;
	palindrome(str, lb, ub);
	return 0;
}

int main()
{
	char str[] = "nittin\0";
	for (int i = 0;i < strlen(str);i++)
	{
		palindrome(str, i, (strlen(str) - 1));
		printf("\n");
	}
}