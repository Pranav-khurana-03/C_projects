#include<iostream>

using namespace std;

int gcd(int num1, int num2)
{
	if(num1==0)
	{
		return num2;
	}
	if(num2==0)
	{
		return num1;
	}
	if(num1>=num2)
	{
		return gcd(num1-num2, num2);
	}
	else
	{
		return gcd(num1, num2-num1);
	}
}

int gcd_mod(int num1, int num2)
{
	if(!num1){
		return num2;
	}
	return gcd_mod(num2%num1, num1);
}

int main()
{
	int num1, num2;
	while(true)
	{
		cin>>num1>>num2;
		cout<<gcd_mod(num1, num2)<<endl;
	}
}