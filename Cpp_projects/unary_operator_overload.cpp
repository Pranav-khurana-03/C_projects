#include<bits/stdc++.h>

using namespace std;


class my_count {
	private:
		int val;

	public:
		my_count() {
			val = 0;
		}
		my_count(int i) {
			val = i;
		}
		my_count operator ++()
		{
			return my_count(++val);
		}
		my_count operator ++(int) {
			return my_count(val++);
		}
		void show()
		{
			cout<<val<<endl;
		}
};


int main()
{
	my_count c1, c3;
	c1.show();
	my_count c2 = ++c1;
	c3 = c2++;
	c1.show();c2.show();c3.show();
}
