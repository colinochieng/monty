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
 * null_f_op - confirms if func_op is assigned null
 * @f: pointer to func_op
 * @stack: pointer to stack_h
 * @op: opcodes
 * Return: bool
*/
bool null_f_op(void (*f)(stack_t **, unsigned int), stack_t **stack, char **op)
{
	if (f == NULL)
	{
		free_stack(stack);
		fprintf(stderr, "L%u: unknown instruction %s\n", line_no, op[0]);
		exit_status = EXIT_FAILURE;
		free_token(op);
		return (true);
	}

	return (false);
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
		if (null_f_op(func_op, &stack_h, opcodes))
			break;
		tok_track = false;
		func_op(&stack_h, line_number);
		if (tok_track)
			break;

		free_token(opcodes);
	}
	free_stack(&stack_h);
	return (exit_status);
}
