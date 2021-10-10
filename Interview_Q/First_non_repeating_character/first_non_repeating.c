#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char letter;
	int pos;
};

struct node arr[26];

int i =1;

int hash(char letter, int *count)
{
	*count = i;
	i++;
	return (int)letter % 26;
}

char first_non_repeating_char(char *str)
{
	int size = strlen(str);
	int position, i;
	for (i = 0; i < size; i++)
	{
		int index = hash(str[i], &position);
		if (arr[index].pos)
		{
			arr[index].letter = '\0';
			arr[index].pos = 0;
		}
		else
		{
			arr[index].letter = str[i];
			arr[index].pos = position;
		}
	}
	char to_return = '\0';
	int track = 0;
	for (i = 0; i < 26; i++)
	{
		if (arr[i].pos)
		{
			if ((!track)||(track>arr[i].pos))
			{
				track =  arr[i].pos;
				to_return = arr[i].letter;
			}
		}
	}
	return to_return;
}

int main()
{
	while (1)
	{
		i = 1;
		char str[50];
		memset(str, 'a', 50);
		memset(arr, 0, sizeof(struct node)*26);
		scanf("%s", str);
		char result = first_non_repeating_char(str);
		printf("%c\n", result);
	}
}