#include "monty.h"

/**
 * free_my_list_stack - Function that frees memory of the stack
 * @head: Head of the stack
 */
void free_my_list_stack(stack_t *head)
{
	stack_t *tempo;

	while (head)
	{
		tempo = head;
		head = head->next;
		free(tempo);
	}
}
