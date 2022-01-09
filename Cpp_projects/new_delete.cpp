#include<bits/stdc++.h>

using namespace std;

struct tmp {
	int age;
	int val;
	int num;
};

int main()
{
	// tmp* t1 = new tmp;
	// int* p3 = new int[50];
	// int* i1 = new int;
	// cout<<t1<<" "<<i1<<endl;
	// for(int i = 0; i<50;i++)
	// {
	//     cout<<p3[i];
	// }
	int size;
	cin>>size;
	tmp t1;
	t1.num = 5;
	tmp **records = new tmp*[size];
	for (int i = 0;i<size;i++)
	{
		records[i] = new tmp;
		cout<<"Enter a record: age, val, num"<<endl;
		cin>>records[i]->age>>records[i]->val>>records[i]->num;
	}
	for(int i = 0;i<size;i++)
	{
		cout<<records[i]->num<<endl;
	}
}
