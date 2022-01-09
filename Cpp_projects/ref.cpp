#include<iostream>

using namespace std;

void make_one(int& q)
{
	q = 1;
}

void make_zero(int &p)
{
	p = 0;
	make_one(p);
}


int main()
{
	int p = 2;
	cout<<p;
	make_zero(p);
	cout<<p;

}
