#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * stack_init - initailize the first character
 * @stack: pointer to stack_t
 * Return: exit value
*/
int stack_init(stack_t **stack)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));

	if (ptr == NULL)
	{
		handle_error(MALLOC, &exit_status);
		return (exit_status);
	}

	ptr->n = STACK;
	ptr->prev = NULL;
	ptr->next = NULL;

	*stack = ptr;

	return (EXIT_SUCCESS);
}

/**
*free_line - frees line memory
*@line: opcode line
*Return: void
*/

void free_line(char *line)
{
	if (line && *line != 0)
	{
		free(line);
		handle_error(MALLOC, &exit_status);
	}
	free(line);
}
/**
 * read_monty - co-ordinates programs
 * @stream: file pointer
 * Return: exit status
*/
int read_monty(FILE *stream)
{
	stack_t *stack_h = NULL;
	char line[1024];
	unsigned int line_number = 1;
	void (*func_op)(stack_t **, unsigned int);

	if (stack_init(&stack_h) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	for (; fgets(line, sizeof(line), stream) != NULL; line_number++)
	{
		line_no = line_number;
		opcodes = split(line, DELIMS);
		if (opcodes == NULL)
		{
			if (null_line(line, DELIMS))
				continue;
			free_stack(&stack_h);
			handle_error(MALLOC, &exit_status);
		}
		else if (opcodes[0][0] == '#')
		{
			free_token(opcodes);
		       	continue;
		}
		func_op = get_function(opcodes[0]);
		if (func_op == NULL)
		{
			free_stack(&stack_h);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcodes[0]);
			exit_status = EXIT_FAILURE;
			free_token(opcodes);
			break;
		}
		tok_track = false;
		func_op(&stack_h, line_number);
		if (tok_track)
		{
			exit_status = EXIT_FAILURE;
			free_token(opcodes);
			break;
		}
	}
	free_stack(&stack_h);
	return (exit_status);
}
