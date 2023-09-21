#include "monty.h"

/**
 * instructioncreation - function creates a
 * node in the list of opcode
 * @head: opcode head linked list
 * @str: addition of the string to the L list
 * @n: input variable - number of the line
 * @fp: open file
 * Return: (0) on Success otherwise -1 in failure
 */

list_t *instructioncreation(list_t **head, char *str, int n, FILE *fp)
{
	list_t *current = NULL;
	list_t *previous = NULL;

	current = malloc(sizeof(list_t));
	if (current == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (list_opcode)
			free_list_opcode(list_opcode);
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	current->n = n;
	current->inst = _strdup(str, fp);
	current->next = NULL;

	n++;

	if (*head == NULL)
	{
		*head = current;
		return (*head);
	}

	prev = *head;

	while (prev->next)
		prev = prev->next;

	prev->next = current;

	return (*head);
}
