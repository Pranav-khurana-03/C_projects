#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void add(struct node** head, int data)
{
	struct node* to_add = (struct node*)malloc(sizeof(struct node));
	to_add->data = data;
	to_add->next = NULL;
	if(!(*head) || (*head)->data>data)
	{
		to_add->next = (*head);
		*head = to_add;
		return;
	}
	struct node*tmp = *head;
	struct node*prev;
	while(tmp)
	{
		if(tmp->data==data){
			free(to_add);
			return;
		}
		if(tmp->data < data){
			prev = tmp;
			tmp = tmp->next;
			continue;
		}
		prev->next = to_add;
		to_add->next= tmp;
		return;
	}
	prev->next = to_add;
	to_add->next = NULL;
}

void show_list(struct node* head){
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

int main()
{
	struct node* head = NULL;
	for(int i = 0;i<5;i++)
	{
		int a;
		scanf("%d", &a);
		add(&head, a);
		show_list(head);
		printf("\n");
	}
	show_list(head);
}
