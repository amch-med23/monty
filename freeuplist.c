#include "monty.h"

/**
 * free_my_list_opcode - Function that frees the opcode linked list
 * @head: Head of the linked list
 */
void free_my_list_opcode(list_t *head)
{
	list_t *tempo;

	while (head)
	{
		tempo = head;
		head = head->next;
		free(tempo->inst);
		free(tempo);
	}
}
