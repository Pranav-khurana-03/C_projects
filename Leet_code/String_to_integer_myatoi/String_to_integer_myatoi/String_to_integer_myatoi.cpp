#include<stdio.h>
#include<math.h>



int myAtoi(char* str) {
	int size = 0, i = 0;
	int index = 0;
	bool sign = false;
	bool digit = false;
	for (i = 0;str[i] != '\0';i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			if ((size == 0) && (str[i] == '0'))//TODO
			{
				digit = true;
				index++;
				continue;
			}
			size++;
		}
		else if ((str[i] == ' ') && (size == 0))
		{
			index++;
		}
		else if ((str[i] == '-') && (size == 0) && (!digit))
		{
			index++;
			sign = true;
			digit = true;
		}
		else if ((str[i] == '+') && (size == 0) && (!digit))
		{
			digit = true;
			index++;
		}
		else
		{
			break;
		}
	}
	if (size > 10)//TODO
	{

		if (sign)
		{
			return -2147483648;
		}
		else
		{
			return 2147483647;
		}
	}
	long  multiplier = (int)pow(10, size - 1);
	long long int result = 0;
	if (sign)
	{
		for (i = 0;i < size;i++)
		{
			result = result - multiplier * (str[index] - '0');
			multiplier = multiplier / 10;
			index++;
		}
	}
	else
	{
		for (i = 0;i < size;i++)
		{
			result = result + multiplier * (str[index] - '0');
			multiplier = multiplier / 10;
			index++;
		}
	}
	if (result < -2147483648)
	{
		return -2147483648;
	}
	else if (result > 2147483648)
	{
		return 2147483647;
	}
	return result;
}
int main()
{
	char str[50];
	while (1)
	{
		gets_s(str);
		printf("%d", myAtoi(str));
		printf("\n");
	}

}