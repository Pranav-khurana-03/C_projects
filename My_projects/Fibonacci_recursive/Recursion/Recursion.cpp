#include<stdio.h>

int fibo(int ub)
{
	int sum = 0;
	if (ub <= 1)
	{
		return 0;
	}
	else if (ub == 2)
	{
		return 1;
	}
	int num1 = fibo(ub - 2);
	int num2 = fibo(ub - 1);
	sum = num1 + num2;
	//printf("%d: %d \n", ub,sum);
	return sum;

}

int main()
{
	printf("%d", fibo(4));
}