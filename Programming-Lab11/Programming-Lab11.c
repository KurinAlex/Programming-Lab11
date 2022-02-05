#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIFFERENT_CHARS_NUMBER 2

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
	printf("Enter n: ");
	scanf_s("%d", &n);
	getchar();

	char* s = (char*)calloc(n, sizeof(char));
	do
	{
		printf("\nEnter s of size less than or equal n:\n");
		gets(s);
	} while (strlen(s) > n);

	char* output = (char*)calloc(n, sizeof(char));
	char* word = strtok(s, " ");
	while (word)
	{
		if (IsValid(word))
		{
			strcat(output, word);
			strcat(output, " ");
		}
		word = strtok(NULL, " ");
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
	free(word);

	getchar();
}