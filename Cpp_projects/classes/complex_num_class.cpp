#include<bits/stdc++.h>

using namespace std;

class comp_num {
	private:
		float real;
		float img;
	public:
		comp_num(){
			real = 0;
			img = 0;
		}
		comp_num(float r, float i) {
			real = r;
			img = i;
		}
		void set_data(int r, int i) {
			real = r;
			img = i;
		}
		void get_data() {
			int r,i;
			cout<<"Enter real followed by imaginary"<<endl;
			cin>>r>>i;
			real = r;
			img = i;
		}
		comp_num operator + (comp_num c1) {
			comp_num c2;
			c2.real = c1.real * real;
			c2.img = c1.img * img;
			return c2;
		}
		comp_num operator * (comp_num c1) {
			comp_num c2;
			c2.real = real * c1.real;
			c2.img = img * c1.img;
			return c2;
		}
		void add(comp_num c1, comp_num c2) {
			real = c1.real + c2.real;
			img = c1.img + c2.img;
		}
		void show_data() {
			cout<<"Real: "<<real<<endl<<"Img: "<<img<<endl;
		}
};


int main()
{
	comp_num c1;
	comp_num c2, c3;
	c1.show_data();
	c2.set_data(1, 5);
	c3.set_data(5, 4);
	comp_num c4;
	c4.set_data(4, 1);
	c3.show_data();
	c4.show_data();
	c1 = c2+ c3 * c4; //c1 = c2.operator+( c3.operator *(c4));
	c1.show_data();
}
