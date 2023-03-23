#include "monty.h"

/**
 * read_monty - co-ordinates programs
 * @stream: file pointer
 * Return: exit status
*/
int read_monty(FILE *stream)
{
	stack_t *stack_h = NULL;
	char *line = NULL;
	int exit_status = EXIT_SUCCESS;
	size_t len = 0;
	size_t line_number;
	char **opcodes = NULL;
	void (*func_op)(stack_t **, size_t);

	for (line_number = 0; getline(&line, &len, stream) != -1; line_number++)
	{
		opcodes = split(line, DELIMS);
		if (opcodes == NULL)
		{
			if (null_line(line, DELIMS))
				continue;
			free_stack(stack_h);
			fprintf(stderr, "Error: malloc failed");
			exit_status = EXIT_FAILURE;
		}
		else if (opcodes[0][0] == '#')
		{
			free_token(opcodes);
			continue;
		}
		func_op = get_function(opcodes[0]);
		if (func_op == NULL)
		{
			free_stack(stack_h);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcodes[0]);
			exit_status = EXIT_FAILURE;
			free_token(opcodes);
			break;
		}
	/**
	* This Code needs to be completed from here
	* there id need to call the functions func_op
	* if there is an from called function value of exit_status needs to be changed
	* So we need to develop all the functions according responsible functions while handling the errors
	* 
	*/

	}
}
