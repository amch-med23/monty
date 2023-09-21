#include "monty.h"

/**
 * nop_opcode - Function useless
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void nop_opcode(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	;
}


/**
 * pop_opcode - Function that remove the head of stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n <= 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
	temp = NULL;
}

/**
 * push_opcode - Function that pushes nodes in the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_core_queue(stack, line_number, 0);
}


/**
 * stack_list - Function that pushes nodes in the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void stack_list(stack_t **stack, unsigned int line_number)
{
	stack_core_queue(stack, line_number, 1);
}


/**
 * queue_list - Function that pushes nodes in the queue
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void queue_list(stack_t **stack, unsigned int line_number)
{
	stack_core_queue(stack, line_number, 2);
}
