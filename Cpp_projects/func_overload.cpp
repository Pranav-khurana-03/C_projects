#include<bits/stdc++.h>

using namespace std;

struct complex_num {
	int real;
	int img;
};


int add (int a, int b)
{
	return a + b;
}

float add (float a, float b, float c = 3.0)
{
	return a + b + c;
}

complex_num add (complex_num a, complex_num b)
{
	complex_num c;
	c.real = a.real + b.real;
	c.img = a.img + b.img;
	return c;
}


void display(char *str)
{
	cout<<str<<endl;
}

void display(const char* str)
{
	cout<<"CONST: "<<str;
}

int main()
{
	complex_num c1, c2;
	c1.real = 1;
	c1.img = 3;
	c2.img  = 4;
	c2.real = 2;
	complex_num c3 = add(c1, c2);
	cout<<c3.real<<" "<<c3.img<<endl;
	cout<<add(2, 3)<<endl;
	float f1= 2.11;
	float f2= 3.11;
	cout<<add(f1, f2, 0);
	display("LOL");
	const char str[] = "LOL";
	display(str);
	
}
