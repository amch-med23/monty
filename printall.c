#include "monty.h"

/**
 * pall_zstacks - function that prints all the stacks
 * @stack: stack structure
 * @line_number: number of instructions
 */

void pall_zstacks(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = NULL;
	int n = 0;

if (*stack == NULL)
	return;

tempo = *stack;

while (tempo)
{
	n = tempo->n;
	printf("%d", n);
	tempo = tempo->next;
}
}
