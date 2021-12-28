#include <stdio.h>

struct type {
	int physics : 8;
	int chemistry : 8;
	int maths : 8;
	int biology : 8;
};

int main()
{
	struct type marks;
	printf("Enter your marks in physics: ");
	scanf("%d", marks.physics);
	printf("Enter your marks in chemisry: ");
	scanf("%d", marks.chemistry);
	printf("Enter your marks in maths: ");
	scanf("%d", marks.maths);
	printf("Enter your marks in biology: ");
	scanf("%d", marks.biology);
	printf("Your marks in physics are: %d\n", marks.physics);
	printf("Your marks in maths are: %d\n", marks.maths);
	printf("Your marks in chemistry are: %d\n", marks.chemistry);
	printf("Your marks in biology are: %d\n", marks.biology);
}