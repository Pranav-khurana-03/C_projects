#include<bits/stdc++.h>

using namespace std;

class employee{
	private:
		int age;
		char name[40];
	public:
		employee();
		employee(char* n, int a);
		void get_data();
		void display();
};


employee::employee()
{
	strcpy(name, "");
	age = 0;
}

employee::employee(char*n, int a)
{
	strcpy(name, n);
	age = a;
}

void employee::get_data()
{
	char tmp[40];
	cout<<"Enter name";
	cin>>tmp;
	strcpy(name, tmp);
	cout<<"Enter age: ";
	cin>>age;
}

void employee::display()
{
	cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
}


int main()
{
	employee e1((char*)"Name", 5);
	e1.display();
	e1.get_data();
	e1.display();
}
