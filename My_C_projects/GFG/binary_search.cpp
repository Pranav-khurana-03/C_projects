#include<iostream>

using namespace std;

bool bs(int *arr, int num, int size)
{
	int low = 0;
	int high = size-1;
	int cur = size/2;
	while(high>=low)
	{
		if(arr[cur]>num)
		{
			high = cur-1;
			cur =(high+low)/2; //low + (high-low)/2;
		}
		else if(arr[cur]<num)
		{
			low = cur+1;
			cur = (high+low)/2; //low + (high-low)/2;
		}
		else
		{
			return true;
		}
	}
	return false;

}
	int main()
{
	int num;   //0  1  2  3  4  5   6   7   8   9   10  11  12  13  14
	int arr[] = {1, 3, 6, 7, 8, 11, 14, 17, 19, 21, 23, 25, 27, 29, 31};
	while(true)
	{
		cin>>num;
		bool present = bs(arr, num, 15);
		cout<<present<<endl;

	}
}