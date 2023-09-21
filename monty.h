#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - L list of struct instruction
 * @n: number of line
 * @inst: instruction of opcode and its function
 * @next: points to the next element of the L list
 */
typedef struct list_s
{
	int n;
	char *inst;
	struct list_s *next;
} list_t;

extern list_t *list_opcode;

/* Functions */

int open_file(char *mystr);
list_t *instructioncreation(list_t **head, char *str, int n, FILE *fp);
void (*pointer_opcode(list_t *head))(stack_t **stack, unsigned int line_number);
char *str_dup(char *str, FILE *fp);
int str_len(char *str);
int stack_length(stack_t *head);
int cgrab_string_length(char *buffer, char *str);
void free_my_list_opcode(list_t *head);
void free_my_list_stack(stack_t *head);
void *my_calloc(unsigned int nmemb, unsigned int size);
void push_stack(stack_t **stack, unsigned int line_number);
void my_stack(stack_t **stack, unsigned int line_number);
void my_q(stack_t **stack, unsigned int line_number);
void pall_zstacks(stack_t **stack, unsigned int line_number);
void pintit(stack_t **stack, unsigned int line_number)
void is_nothing(stack_t **stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, UN unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void nop_stack(UN stack_t **stack, UN unsigned int line_number);
