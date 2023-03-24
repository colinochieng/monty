#include "monty.h"

/**
 * mod -  computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * If the top element of the stack is 0
 *      generates zero error
 * from the second top element of the stack
 * followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;
	if (ptr == NULL || ptr->next == NULL)
	{
		handle_error(DIV, &exit_status);
		return;
	}
	if (ptr->n == 0)
	{
		handle_error(ZERO_ER1, &exit_status);
		return;
	}

	ptr->next->n %= ptr->n;
	pop(stack, line_number);
}

