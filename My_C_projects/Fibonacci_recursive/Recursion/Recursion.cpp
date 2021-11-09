#include<stdio.h>

int fibo(int num)
{
  if(num==1)
    return 1;
  if(num==0)
    return 0;
  return fibo(num-1) + fibo(num-2);
}

int main()
{
  int i;
  while(true)
  {
    printf("i*i = %d\n", 5);
  }
}
