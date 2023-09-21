#include "monty.h"

/**
 * pall_opcode - Function that prints the stack
 * @stack: stack structure
 * @line_number: number of instruction
 */

void pall_opcode(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *temp = NULL;
	int n = 0;

	if (*stack == NULL)
		return;

	temp = *stack;

	while (temp)
	{
		n = temp->n;
		printf("%d\n", n);
		temp = temp->next;
	}
}


/**
 * pint_opcode - prints the value at the top of the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */

void pint_opcode(stack_t **stack, unsigned int line_number)
{


	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pstr_opcode - Function that prints string of the stack
 * @stack: stack structure
 * @line_number: number of instruction
 */
void pstr_opcode(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		putchar(10);
		return;
	}

	temp = *stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n >= 128)
		{
			putchar(10);
			return;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	putchar(10);
}

/**
 * pchar_opcode - Function that prints character at the top
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		if (list_opcode)
			free_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		if (*stack)
			free_stack(*stack);
		if (list_opcode)
			free_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * swap_opcode - Function that swaps top values
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len_op(*stack);
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		if (list_opcode != NULL)
			free_opcode(list_opcode);
		if (*stack != NULL)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if (n == 2)
	{
		temp = (*stack)->next;
		(*stack)->next = NULL;
		(*stack)->prev = temp;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev = temp;
		temp->next->prev = *stack;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
