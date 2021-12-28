#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	cin>>a;
	int squares = 0, cubes=0;
	int root;
	int c_root;
	bool sqroot = false, cbroot = false;
	for(int i = a-1;i>0;i--)
	{
		c_root = cbrt(i);
		root = sqrt(i);
		if(!sqroot && root*root == i)
		{
			sqroot = true;
			break;
		}
		if(!cbroot && c_root*c_root*c_root == i)
		{
			cbroot = true;
			break;
		}
	}
	squares += root;
	cubes += c_root;
	cout<<squares;
	cout<<cubes;
}
