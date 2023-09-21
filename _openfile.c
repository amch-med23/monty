#include "monty.h"

/*
 * open_file - a function to open the file by motny bytecode files
 * @mystr: string to be checked
 * Return: Line counter otherwise on failure EXIT_FAILURE
*/

int open_file(char *mystr);
{
	char *line_buffer = NULL, buff[10024], *b = buff;
	size_t line_buffer_size = 0;
	int line_counter = 0, i, j;
	ssize_t line_size = 0;
	FILE *fp = fopen(str, "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	line_size = getline(&line_buffer, &line_buffer_size, fp);
	for (i = 0; i < 10024; i++)
		buff[i] = 0;
	while (line_size >= 0)
	{
		for (i = 0, j = 0; line_buffer[i] && line_buffer[i] != '\n'; i++)
		{
			if (line_buffer[i] != ' ')
			{
				j++;
				break;
			}
		}
		if (line_buffer[i] == '#')
		{
			line_size = getline(&line_buffer, &line_buffer_size, fp);
			line_counter++;
			continue;
		}
		line_counter++;
		if (j > 0)
		{
			clean_string(b, line_buffer);
			create_instruction(&list_opcode, b, line_counter, fp);
		}
		line_size = getline(&line_buffer, &line_buffer_size, fp);
	}
	free(line_buffer), line_buffer = NULL, fclose(fp);
	return (line_counter);
}

