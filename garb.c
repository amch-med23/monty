#include "monty.h"

/**
 * cgrab_string_length - Function that cleans a string
 * @buffer: buffer to store string
 * @str: String to be cleaned
 * Return: The length of string
 */
int cgrab_string_length(char *buffer, char *str)
{
	int i, j, k = 0;

	for (i = 0, j = 0; str[i] && str[i] != '\n'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			buffer[j] = str[i];
			k = 1;
			j++;
		}
		else if (k == 1 && (str[i] == ' ' || str[i] == '\t'))
			break;
	}

	buffer[j] = ' ';
	j++;

	for (; str[i] && str[i] != '\n'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			buffer[j] = str[i];
			k = 2;
			j++;
		}
		else if (k == 2 && (str[i] == ' ' || str[i] == '\t'))
			break;
	}

	buffer[j] = '\0';

	return (j);
}
