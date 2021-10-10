#include<iostream>

using namespace std;

int main()
{
	int num1, num2;
	while(true)
	{
		cin>>num1>>num2;
		int min;
		if(num1>=num2)
		{
			min = num2;
		}
		else
		{
			min = num1;
		}
		int gcd;
		for(int i = 1;i*i<=min; i++)
		{
			if((num1 % i == 0)&&(num2 % i == 0)&&(i>gcd))
			{
				gcd = i;
			}
			if((num1 % (min/i) == 0)&&(num2 % (min/i) ==0)&&((min/i)>gcd))
			{
				gcd = min/i;
				break;
			}
			gcd = 1;
		}
		cout<<gcd<<endl;
	}
}