#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<string.h>

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


void move_element(char* arr, int src, int dest)
{
	if (src == dest)
	{
		return;
	}
	char tmp = arr[src];
	int index = src;
	for (index;index > dest;index--)
	{
		arr[index] = arr[index - 1];
	}
	arr[index] = tmp;
}

/*char* combinations(short int n, int k)
{
	char* str;
	str = (char*)malloc(sizeof(char) * n+1);
	assert(str);
	memset(str, 0, sizeof(char) * n + 1);
	short int index;
	char i = '1';
	for (index=0;index<n;index++, i++)
	{
		str[index] = i;
	}
	double result;
	for (index = 0;index <= n;index++)
	{
		float num = (float)fact(n - 1);
		result = ceil(k / num -1);
		int dest = (int)result;
		move_element(str, index, dest);
		if ((int)num * (int)result)
		{
			k = k - ((int)num * (int)result);
		}
		n--;
	}
	return str;
}*/


char* combinations(int n, int k)
{
	assert(n > 0);
	k--;
	char* str = (char*)malloc((sizeof(char)) * (n + 1));
	assert(str);
	memset(str, 0, sizeof(char) * n + 1);
	int index;
	for (index=0;index < n;index++)
	{
		str[index] = (char)('0' + (index + 1));
	}
	int factorial = n;
	for(index=0;index<n;index++)
	{
		int num = fact(factorial - 1);
		int dest = k / num;
		dest = dest + index;
		move_element(str, dest, index);
		k = k % (int)num;
		if (!k)
		{
			break;
		}
		factorial--;
	}
	return str;
}

/*
* 1234
* 1243
* 1324
* 1342
* 1423
* 1432
* 2134
* 2143
* 2314
* 2341
* 2413
* 2431
*/

int main()
{
	int n, k;
	while (true)
	{
		scanf("%d %d", &n, &k);
		printf("%s", combinations(n, k));
	}
}