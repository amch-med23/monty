#include "monty.h"

list_t *list_opcode = NULL;

/**
 * main - Main entry point for Stacks and Queues
 * @argc: Argument count for the matrix
 * @argv: Argument vector for the matrix
 * Return: 0 on success or other number if it fails
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	list_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ret_file(argv[1]);

	temp = list_opcode;

	for (; temp; temp = temp->next)
		(*opcode_idnf(temp))(&stack, temp->n);

	free_eve(list_opcode, stack);
	return (0);
}
