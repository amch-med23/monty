#include "monty.h"

/**
 * str_len - Function that calculates a length of string
 * @str: String to be checked
 * Return: The length of string or -1 if it fails
 */

int str_len(char *str)
{
	int i;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i]; i++)
		;

	return (i);
}

/**
 * str_dup - Function that returns a pointer to a newly allocated memory
 * @str: String to be allocated
 * @fp: open file
 * Return: Return a string allocated or NULL if it fails
 */

char *str_dup(char *str, FILE *fp)
{
	int i;
	char *new;

	if (str == NULL)
		return (NULL);

	i = str_len(str);

	new = _mem_calloc(i + 1, sizeof(char));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (list_opcode)
			free_opcode(list_opcode);
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < str[i]; i++)
		new[i] = str[i];

	new[i] = '\0';

	return (new);
}
