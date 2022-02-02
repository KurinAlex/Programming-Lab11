#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define DIFFERENT_CHARS_NUMBER 2

int IsValid(const char* s)
{
	char used_chars[DIFFERENT_CHARS_NUMBER];
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		char current_char = s[i];
		int is_used = 0;
		for (int j = 0; j < count; j++)
		{
			if (current_char == used_chars[j])
			{
				is_used = 1;
				break;
			}
		}
		if (!is_used)
		{
			if (count == DIFFERENT_CHARS_NUMBER)
			{
				return 1;
			}
			used_chars[count++] = current_char;
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
	if (n == 0)
	{
		printf("s is empty\n");
	}
	for (int i = 0; i < n; i++)
	{
		printf("s%d: %s\n", i + 1, s[i]);
	}
}