#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

int fact(int num)
{
	if (num == 0)
	{
		return 1;
	}
	int i;
	int result = 1;
	for (i = 1;i <= num;i++)
	{
		result = result * i;
	}
	return result;
}


void move_element(char* arr, int des, int src)
{
	if (des == src)
		return;
	char tmp = arr[des];
	int index = des;
	for (index;index > src;index--)
	{
		arr[index] = arr[index - 1];
	}
	arr[index] = tmp;
}

char* combinations(int n, int k)
{
	k--;
	char* str = (char*)malloc((sizeof(char)) * (n + 1));
	memset(str, 0, sizeof(char)*n+1);
	int index;
	for (index=0;index < n;index++)
	{
		str[index] = (char)('0' + (index + 1));
	}
	int factorial = n-1;
	index = 0;
	while(k)
	{
		int num = fact(factorial);
		int dest = k / num;
		dest = dest + index;
		move_element(str, dest, index);
		k = k % num;
		factorial--;
		index++;
	}
	return str;
}

int main()
{
	int n, k;
	char * res;
	scanf("%d %d", &n, &k);
	res = combinations(n, k);
	printf("%s", res);
}