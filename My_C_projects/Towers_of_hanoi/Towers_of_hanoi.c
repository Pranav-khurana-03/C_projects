#include<stdio.h>

void hanoi(int src, int aux, int dest, int size)
{
	if (size == 1)
	{
		printf("Move disc from %d to %d\n", src, dest);
		return;
	}
	hanoi(src, dest, aux, size - 1);
	printf("Move disc from %d to %d\n", src, dest);
	hanoi(aux, src, dest, size - 1);
}
int main()
{
	hanoi(1, 2, 3, 3);
}