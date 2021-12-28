#include<iostream>

using namespace std;

class List{
	private:
		struct Node {
			int val;
			Node* next;
		};
		Node* head = NULL;
	public:
		void add(int num)
		{
			Node* to_add = new Node;
			to_add->val = num;
			to_add->next = NULL;
			if(!head){
				head = to_add;
				return;
			}
			Node* tmp = head;
			while(tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = to_add;
		}
		void del(int num)
		{
			if(!head)
				return;
			if(head->val == num)
			{
				Node* tmp = head;
				head = head->next;
				delete tmp;
				return;
			}
			Node* tmp = head->next;
			Node* prev = head;
			while(tmp)
			{
				if(tmp->val == num)
				{
					prev->next = tmp->next;
					delete tmp;
					break;
				}
				tmp = tmp->next;
				prev = prev->next;
			}
		}
		void showlist()
		{
			Node* tmp = head;
			while(tmp)
			{
				cout<<tmp->val<<" ";
				tmp = tmp->next;
			}
			cout<<endl;

		}
};


int main()
{
	List l1;
	List l2;
	for(int i = 0;i<5;i++)
	{
		l1.add(i);
	}
	for(int i =32;i>=9;i-=2){
		l2.add(i);
	}
	l1.showlist();
	l2.showlist();
	for(int i = 0;i<5;i+=2)
	{
		l1.del(i);
	}
	for(int i = 32;i>=9;i-=4)
	{
		l2.del(i);
	}
	l1.showlist();
	l2.showlist();
}
