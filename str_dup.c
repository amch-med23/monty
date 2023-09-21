#include "monty.h"

/**
 * str_dup - Function that returns a pointer to a newly allocated memory
 * @str: String to be allocated
 * @fp: open file
 * Return: allocated string
 */

char *str_dup(char *str, FILE *fp)
{
	int i;
	char *current;

	if (str == NULL)
		return (NULL);

	i = str_len(str);

	current = my_calloc(i + 1, sizeof(char));
	if (current == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (list_opcode)
			free_list_opcode(list_opcode);
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < str[i]; i++)
		current[i] = str[i];

	current[i] = '\0';

	return (current);
}
