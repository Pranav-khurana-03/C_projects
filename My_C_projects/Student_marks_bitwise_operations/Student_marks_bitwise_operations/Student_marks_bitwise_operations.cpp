#include <stdio.h>
#include<math.h>


#define MASK 0X000000FF
#define physics 24
#define chemistry 16
#define maths 8
#define biology 0

#define set_marks(marks, new_marks, shift_bits) marks |= new_marks << shift_bits

/*

#define physics 0xff000000
#define chemistry 0x00ff0000
#define maths 0x0000ff00
#define biology 0x000000ff
*/
void showbits(int a)
{
	int mask;
	int i, answer = 0;
	for (i = 31; i >= 0; i--)
	{
		mask = (int)pow(2, i);
		answer = mask & a;
		if (answer)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

void show_marks(int marks)
{
	printf("Marks in physics are : %d\n", (marks & (MASK<<physics))>>physics);
	printf("Marks in chemistry are : %d\n", (marks & (MASK<<chemistry))>>chemistry);
	printf("Marks in maths are : %d\n", (marks &(MASK<<maths))>>maths);
	printf("Marks in biology are : %d\n", (marks & (MASK<<biology))>>biology);
}

int get_marks()
{
	int marks;
	int final_marks = 0;
	printf("Enter your marks in physics\n");
	scanf("%d", &marks);
	set_marks(final_marks, marks, physics);
	printf("Enter your marks in chemistry\n");
	scanf("%d", &marks);
	set_marks(final_marks, marks, chemistry);
	printf("Enter your marks in maths\n");
	scanf("%d", &marks);
	set_marks(final_marks, marks, maths);
	printf("Enter your marks in biology\n");
	scanf("%d", &marks);
	set_marks(final_marks, marks, biology);
	return final_marks;
}

/*
int get_marks()
{
	int marks;
	int final_marks = 0;
	printf("Enter your marks in physics\n");
	scanf("%d", &marks);
	marks = marks << 24;
	final_marks = final_marks | marks;
	//showbits(final_marks);
	printf("Enter your marks in chemistry\n");
	scanf("%d", &marks);
	marks = marks << 16;
	final_marks = final_marks | marks;
	//showbits(final_marks);
	printf("Enter your marks in maths\n");
	scanf("%d", &marks);
	marks = marks << 8;
	final_marks = final_marks | marks;
	//showbits(final_marks);
	printf("Enter your marks in biology\n");
	scanf("%d", &marks);
	final_marks = final_marks | marks;
	//showbits(final_marks);
	return final_marks;
}
*/
int main()
{
	int marks = get_marks();
	show_marks(marks);
}