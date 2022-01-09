#include<bits/stdc++.h>

using namespace std;

class my_class {
	private:
		int num1;
		int num2;
	public:
		my_class() {
			num1 = 1;
			num2 = 0;
		}
		my_class(int a, int b) {
			num1 = a;
			num2 = b;
		}
		void show_data() {
			cout<<this->num1<<" "<<this->num2<<endl;//cout<<num1<<" "<<num2<<endl;
		}
		void set_data(int a, int b) {
			this->num1 = a; //num1 = a;
			this->num2 = b; //num2 = b;
		}
		my_class* show_address() {
			return this;
		}
};


int main()
{
	my_class obj1, obj2;
	obj1.show_data();
	obj1.set_data(5, 6);
	obj1.show_data();
	cout<<obj1.show_address();
	cout<<endl<<&obj2<<" "<<&obj1;

}
