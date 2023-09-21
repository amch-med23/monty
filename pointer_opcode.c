#include "monty.h"

/**
 * pointer_opcode - Pointer function of struct array
 * @head: Head of the list
 * Return: Pointer to an array of structures
 */
void (*pointer_opcode(list_t *head))(stack_t **stack, unsigned int line_number)
{
	int i, n;
	char my_buff[10024];
	list_t *h = head;

	instruction_t arr_ptr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};
	for (i = 0; arr_ptr[i].f; i++)
	{
		n = cmp_inst(head->inst, arr_ptr[i].opcode);
		if (n == 0)
			return (arr_ptr[i].f);
	}
	for (i = 0; i < 10024; i++)
		my_buff[i] = 0;
	for (i = 0; h->inst[i] != '\n' && h->inst[i] && h->inst[i] != ' '; i++)
		my_buff[i] = h->inst[i];
	my_buff[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", head->n, my_buff);
	return (nothing);
}

