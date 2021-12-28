#include<bits/stdc++.h>

using namespace std;

struct complex_num {
	int real;
	int img;
};

void my_swap(int &a, int &b)
{
	int tmp= a;
	a = b;
	b = tmp;
}

void my_swap(complex_num &a, complex_num &b)
{
	complex_num c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	int a = 3;
	int b = 4;
	my_swap(a, b);
	complex_num c1 = {1, 3};
	complex_num c2 = {2, 4};
	my_swap(c1, c2);	
	cout<<a<<b<<endl;
	cout<<c1.real<<c1.img<<endl;
	cout<<c2.real<<c2.img<<endl;
}
