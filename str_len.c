#include "monty.h"

/**
 * str_len - Function calculates length of a string
 * @str: String to be checked
 * Return: The length of string
 */

int str_len(char *str)
{
	int counter;

	if (str == NULL)
		return (-1);

	for (i = 0; str[counter]; counter++)
		;

	return (counter);
}
