#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int bar_height;
	int index;
    struct node* next;
}node;

node* top = NULL;

void push(int height, int indice)
{
    node* to_add = (node*)malloc(sizeof(node));
    to_add->bar_height = height;
	to_add->index = indice;
    if(!top)
        to_add->next = NULL;
    
    else
        to_add->next = top;
    
    top = to_add;
}

void pop()
{
    if(!top)
        return;
    node* tmp = top;
    top = top->next;
    free(tmp);
}

int trap(int* height, int heightSize){
	int water = 0;
	for(int i = 0; i<heightSize;i++)
	{
		if(!height[i])
			continue;
		if(!top){
			push(height[i], i);
			continue;
		}
		int prev = 0;
		while((top) && (top->bar_height <= height[i]))
		{
			water+= (top->bar_height-prev) * (i - top->index - 1);
			prev = top->bar_height;
			pop();
		}
		if(top && prev<height[i])
		{
			water+= (height[i]-prev) * (i - top->index - 1);
			prev = top->bar_height;
		}
		push(height[i], i);
	}
	return water;
}

int main()
{
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	printf("%d", trap(arr, 12));
}