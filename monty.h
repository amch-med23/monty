#ifndef MONTY_H_
#define MONTY_H_

#define UNUSED __attribute__((__unused__))

/* Standard Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

/* Structs and Lists */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - linked list of struct instruction
 * @n: number of line
 * @inst: instruction of opcode and its function
 * @next: points to the next element of the linked list
 * Description: Single linked list of the struct instruction
 */
typedef struct list_s
{
	int n;
	char *inst;
	struct list_s *next;
} list_t;

extern list_t *list_opcode;

/* Prototype Functions */

int ret_file(char *str);
void ch_file(char *str);
list_t *inst_crt(list_t **head, char *str, int n, FILE *fp);
void (*opcode_idnf(list_t *head))(stack_t **stack, unsigned int line_number);
char *str_dup(char *str, FILE *fp);
int str_len(char *str);
int str_cln(char *buff, char *str);
void free_opcode(list_t *head);
void *_mem_calloc(unsigned int nmemb, unsigned int size);
void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void _nothing(stack_t **stack, unsigned int line_number);
int inst_cmp(char *str1, char *str);
stack_t *nodeint_add(stack_t **head, const int n);
void free_eve(list_t *list_opcode, stack_t *stack);
void free_stack(stack_t *head);
void swap_opcode(stack_t **stack, UNUSED unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);
int stack_len_op(stack_t *head);
void pop_opcode(stack_t **stack, unsigned int line_number);
void add_math(stack_t **stack, unsigned int line_number);
void nop_opcode(UNUSED stack_t **stack, UNUSED unsigned int line_number);
void sub_math(stack_t **stack, unsigned int line_number);
int arg_ch(char *buff);
int arg_cpy(list_t *t, char *buff);
void show_error_push(stack_t **stack, int line_number);
void _div_math(stack_t **stack, unsigned int line_number);
void _mul_math(stack_t **stack, unsigned int line_number);
void _mod_math(stack_t **stack, unsigned int line_number);
stack_t *dnodeint_add_end(stack_t **head, const int n);
void stack_core_queue(stack_t **stack, unsigned int line_number, int sq);
void queue_list(stack_t **stack, unsigned int line_number);
void stack_list(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, UNUSED unsigned int line_number);
void rotl_op(stack_t **stack, UNUSED unsigned int line_number);
void rotr_op(stack_t **stack, UNUSED unsigned int line_number);

#endif /* MONTY_H_ */
