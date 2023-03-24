#include "monty.h"
/**
 * handle_error - prints error
 * @err: enum error value
 * @exit_st: exit status
 * Return: void
*/
void handle_error(enum error_type err, int *exit_st)
{
	switch (err)
	{
		case MALLOC:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case NO_INT:
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			break;
		case STACK_EM:
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
			break;
		case SWAP:
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
			break;
		case ADD:
			fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
			break;
		case SUB:
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_no);
			break;
		case DIV:
			fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
			break;
		case ZERO_ER1:
			fprintf(stderr, "L%u: division by zero\n", line_no);
			break;
		case MOD:
			fprintf(stderr, "L%u: can't mod, stack too\n", line_no);
			break;
		case MUL:
			fprintf(stderr, "L%u: can't mul, stack too short\n", line_no);
			break;
		default:
			break;
	}
	*exit_st = EXIT_FAILURE;
}

/**
 * handle_error2 - prints error
 * @err: enum error value
 * @exit_st: exit status
 * Return: void
*/
void handle_error2(enum error_type err, int *exit_st)
{
	switch (err)
	{
		case PCHAR:
			fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
			break;
		case OUT_OF_RANGE:
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
			break;
		default:
			break;
	}
	*exit_st = EXIT_FAILURE;
}
