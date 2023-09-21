#include "monty.h"

/**
 * stack_core_queue - Function that manages stack and queue
 * @stack: stack structure
 * @line_number: Number of instructions
 * @sq: switch of stack and queue
 */
void stack_core_queue(stack_t **stack, unsigned int line_number, int sq)
{
	static int turn;
	int i, j;
	char buff[10024];
	char *b = buff;
	list_t *t = NULL;

	if (sq != 0)
	{
		turn = sq;
		return;
	}

	t = list_opcode;

	for (; t->next; t = t->next)
		if (t->n == (int) line_number)
			break;

	i = arg_cpy(t, b);

	j = arg_ch(b);

	if (i == 0 || j == 0)
		show_error_push(stack, line_number);

	if (turn == 1)
		nodeint_add(stack, atoi(buff));
	else if (turn == 2)
		dnodeint_add_end(stack, atoi(buff));
	else
		nodeint_add(stack, atoi(buff));
}

/**
 * show_error_push - function that prints error
 * @stack: stack structure
 * @line_number: Number of instruction
 */
void show_error_push(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	if (*stack)
		free_stack(*stack);
	if (list_opcode)
		free_opcode(list_opcode);
	exit(EXIT_FAILURE);
}


/**
 * stack_len_op - Function that calculates the lengt of stack
 * @head: Head of the stack
 * Return: the length
 */
int stack_len_op(stack_t *head)
{
	int i = 0;

	for (; head; head = head->next, i++)
		;

	return (i);
}
