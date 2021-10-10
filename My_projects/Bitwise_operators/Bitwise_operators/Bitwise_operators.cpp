#include<stdio.h>
#include<math.h>
#define happy 0x1
#define is_happy(x) x & happy
#define smart 0x2
#define is_smart(x) x & smart
#define fat 0x4
#define is_fat(x) x & fat
#define exercise 0x8
#define does_exercise(x) x & exercise
#define school 0x10
#define is_in_school(x) x & school
#define gender 0x20
#define is_male(x) x & gender
#define is_healthy(x) ((x & happy)&&(x & exercise))

void showbits(char a)
{
	char mask;
	int i, answer = 0;
	for (i = 7; i >= 0; i--)
	{
		mask = (char)pow(2, i);
		answer = mask & a;
		if (answer)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

char get_answers()
{
	char y_n;
	char answers;
	answers = 0;
	printf("Are you happy?[y/n]\n");
	scanf("%c", &y_n);
	if (y_n == 'y')
	{
		answers = answers | happy;
	}
	scanf("%c", &y_n);
	printf("Are you smart?[y/n]\n");
	scanf("%c", &y_n);
	if (y_n == 'y')
	{
		answers = answers | smart;
	}

	scanf("%c", &y_n);
	printf("Are you fat?[y/n]\n");
	scanf("%c", &y_n);
	if (y_n == 'y')
	{
		answers = answers | fat;
	}
	scanf("%c", &y_n);
	printf("Do you exercise?[y/n]\n");
	scanf("%c", &y_n);
	if (y_n == 'y')
	{
		answers = answers | exercise;
	}
	scanf("%c", &y_n);
	printf("Are you in school?[y/n]\n");
	scanf("%c", &y_n);
	if (y_n == 'y')
	{
		answers = answers | school;
	}
	scanf("%c", &y_n);
	printf("Are you a male?[y/n]\n");
	scanf("%c", &y_n);
	if (y_n == 'y')
	{
		answers = answers | gender;
	}
	return answers;
}

void show_answers(char answers)
{
	if (is_happy(answers))
	{
		printf("You are happy\n");
	}
	else
	{
		printf("You are not happy\n");
	}
	if (is_smart(answers))
	{
		printf("You are smart\n");
	}
	else
	{
		printf("You are not smart\n");
	}
	if (is_fat(answers))
	{
		printf("You are fat\n");
	}
	else
	{
		printf("You are not fat\n");
	}
	if (does_exercise(answers))
	{
		printf("You exercise\n");
		if (is_fat(answers))
		{
			printf("You will lose weight\n");
		}
		else
		{
			printf("Keep it up!\n");
		}
	}
	else
	{
		printf("You don't exercise\n");
		if (is_fat(answers))
		{
			printf("You will become fatter\n");
		}
		else
		{
			printf("You will become fat if you don't exercise\n");
		}
	}
	if (is_in_school(answers))
	{
		printf("You are in school\n");
	}
	else
	{
		printf("You are not in school\n");
	}
	if (is_male(answers))
	{
		printf("You are a male\n");
	}
	else
	{
		printf("You are a female\n");
	}
	if (is_healthy(answers))
	{
		printf("You are healthy\n");
	}
	else
	{
		if (!(is_happy(answers)))
		{
			printf("You should be happier\n");
		}
		else if (!(does_exercise(answers)))
		{
			printf("You should exercise\n");
		}
	}
}

int main()
{
	char answers = get_answers();
	showbits(answers);
	show_answers(answers);
	printf("%#x\n", answers);
}