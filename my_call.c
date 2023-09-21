#include "monty.h"

/**
 * my_calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of bytes
 * Return: a pointer to the allocated memory on success otehrwise -1
 */

void *my_calloc(unsigned int nmemb, unsigned int size)
{
	char *c;
	unsigned int a;

	if (nmemb == 0 || size == 0)
		return (NULL);

	c = malloc(nmemb * size);

	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (list_opcode)
			free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	for (a = 0; a < (nmemb * size); a++)
		p[a] = 0;

	return (c);
}
