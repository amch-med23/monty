#include "monty.h"

/**
 * opcode_idnf - Pointer function of struct array
 * @head: Head of the list
 * Return: pointer to an array of structures
 */

void (*opcode_idnf(list_t *head))(stack_t **stack, unsigned int line_number)
{
	int i, n;
	char buff[10024];
	list_t *h = head;

	instruction_t arr_ptr[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_math},
		{"nop", nop_opcode},
		{"sub", sub_math},
		{"div", _div_math},
		{"mul", _mul_math},
		{"mod", _mod_math},
		{"queue", queue_list},
		{"stack", stack_list},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
		{NULL, NULL}
	};
	for (i = 0; arr_ptr[i].f; i++)
	{
		n = inst_cmp(head->inst, arr_ptr[i].opcode);
		if (n == 0)
			return (arr_ptr[i].f);
	}
	for (i = 0; i < 10024; i++)
		buff[i] = 0;
	for (i = 0; h->inst[i] != '\n' && h->inst[i] && h->inst[i] != ' '; i++)
		buff[i] = h->inst[i];
	buff[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", head->n, buff);
	return (_nothing);
}
