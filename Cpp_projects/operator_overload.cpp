#include<bits/stdc++.h>

using namespace std;

class complex_num{
	private:
		int real;
		int img;
	public:
		void add_to_self(int my_real, int my_img)
		{
			real += my_real;
			img += my_img;
		}
		void add(complex_num c1, complex_num c2)
		{
			real = c1.real + c2.real;
			img = c1.img + c2.img;
		}
		void print()
		{
			cout<<"Real: "<<real<<endl;
			cout<<"Img: "<<img<<endl;
		}
		complex_num(){
			real = 0;
			img = 0;
		}
		complex_num operator + (complex_num c1)
		{
			complex_num tmp;
			tmp.real = c1.real + real;
			tmp.img = c1.img + img;
			return tmp;
		}	
};

struct complex_num_my{
	int real,img;
};

complex_num_my operator + (complex_num_my c1, complex_num_my c2)
{
	complex_num_my c3;
	c3.real = c1.real + c2.real;
	c3.img = c1.img + c2.img;
	return c3;
}

int main()
{
	complex_num my_num, c1, c2;
	c1.add_to_self(1,4);
	c2.add_to_self(3, 8);
	c1.print();
	c2.print();
	my_num.add_to_self(4, 5);
	my_num.print();
	my_num.add(c1, c2);
	my_num.print();
	complex_num c4 = c1 + c2;
	c4.print();
	complex_num_my co1, co2, co3;
	co1.real = 5;
	co1.img = 6;
	co2.real = 7;
	co2.img = 8;
	co3 = co1 + co2;
	cout<<co3.real<<co3.img;
}
