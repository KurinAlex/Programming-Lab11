#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIFFERENT_CHARS_NUMBER 2
#define DELIMETER " "

int CheckInput(char* s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && s[i] != ' ')
		{
			return 0;
		}
	}
	return 1;
}

int IsValid(char* s)
{
	char used_chars[DIFFERENT_CHARS_NUMBER];
	int different_chars_count = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		char current_char = s[i];
		int is_used = 0;
		for (int j = 0; j < different_chars_count; j++)
		{
			if (current_char == used_chars[j])
			{
				is_used = 1;
				break;
			}
		}
		if (!is_used)
		{
			if (different_chars_count == DIFFERENT_CHARS_NUMBER)
			{
				return 1;
			}
			used_chars[different_chars_count++] = current_char;
		}
	}
	return 0;
}

int main()
{
	int n;
	do
	{
		printf("Enter n, which is bigger or equal 1: ");
		scanf("%d", &n);
	} while (n < 1);
	getchar();

	char* s = (char*)calloc(n + 1, sizeof(char));
	do
	{
		printf("\nEnter s of size less than or equal n, which includes only english letters and spaces:\n");
		scanf("%[^\n]s", s);
		getchar();
	} while (strlen(s) > n || !CheckInput(s));

	int len = strlen(s) + 1;
	s = (char*)realloc(s, len * sizeof(char));

	char* output = (char*)calloc(len + 1, sizeof(char));
	s = strtok(s, DELIMETER);
	int is_previous = 0;
	while (s)
	{
		if (IsValid(s))
		{
			if (is_previous)
			{
				strcat(output, DELIMETER);
			}
			strcat(output, s);
			is_previous = 1;
		}
		s = strtok(NULL, DELIMETER);
	}

	printf("\ns after executing:\n");
	if (strlen(output) == 0)
	{
		printf("s is empty\n");
	}
	else
	{
		printf("%s\n", output);
	}

	free(s);
	free(output);

	getchar();
}