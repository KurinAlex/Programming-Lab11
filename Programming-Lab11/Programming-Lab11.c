#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define DIFFERENT_CHARS_NUMBER 2

int IsValid(char* s)
{
	char used_chars[DIFFERENT_CHARS_NUMBER];
	int count = 0;
	int len = strlen(s);
	int i = 0;

	while (i < len && count < DIFFERENT_CHARS_NUMBER)
	{
		char ch = toupper(s[i++]);
		int is_used = 0;
		for (int j = 0; j < count; j++)
		{
			if (ch == used_chars[j])
			{
				is_used = 1;
				break;
			}
		}
		if (!is_used)
		{
			used_chars[count++] = ch;
		}
	}

	while (i < len)
	{
		char ch = toupper(s[i++]);
		for (int j = 0; j < DIFFERENT_CHARS_NUMBER; j++)
		{
			if (ch != used_chars[j])
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf_s("%d", &n);
	getchar();
	printf("\n");

	char** s = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = (char*)calloc(MAX_SIZE, sizeof(char));
		printf("Enter s%d: ", i + 1);
		gets_s(s[i], MAX_SIZE);
	}
	printf("\n");

	for (int i = 0; i < n;)
	{
		if (IsValid(s[i]))
		{
			i++;
		}
		else
		{
			n--;
			for (int j = i; j < n; j++)
			{
				s[j] = s[j + 1];
			}
		}
	}

	printf("s after executing:\n");
	for (int i = 0; i < n; i++)
	{
		printf("s%d: %s\n", i + 1, s[i]);
	}
}