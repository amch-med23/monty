#include "monty.h"

/**
 * sub_math - Function that sub top values
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void sub_math(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n -= temp->n;
	pop_opcode(stack, line_number);
}

/**
 * add_math - Function that adds top values
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void add_math(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n += temp->n;
	pop_opcode(stack, line_number);
}


/**
 * _div - Function that divides top values
 * @stack: stack structure
 * @line_number: Number of instructions
 */

void _div_math(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n /= temp->n;
	pop_opcode(stack, line_number);
}
/**
 * _mul_math - Function that multiplicates top values
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void _mul_math(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n *= temp->n;
	pop_opcode(stack, line_number);
}

/**
 * _mod_math - Function that mod top values
 * @stack: stack structure
 * @line_number: Number of instructions
 */

void _mod_math(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n %= temp->n;
	pop_opcode(stack, line_number);
}
