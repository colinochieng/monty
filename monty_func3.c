#include "monty.h"

/**
 * mul - multiplies the second top element
 * of the stack with the top element of the stack.
 * followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	if (ptr == NULL || ptr->next == NULL)
	{
		handle_error(MUL, &exit_status);
		return;
	}

	ptr->next->n *= ptr->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top
 * of the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;
	int n;

	(void)line_number;

	if (ptr == NULL)
	{
		handle_error2(PCHAR, &exit_status);
		return;
	}
	n = ptr->n;

	if (n < 0 || n > 127)
	{
		handle_error2(OUT_OF_RANGE, &exit_status);
		return;
	}

	printf("%c\n", n);
}

/**
 * add - prints the string starting at
 * the top of the stack, followed by a new line
 * The string stops when either:
 *      the stack is over
 *      the value of the element is 0
 *      the value of the element is not in the ascii table
 * If the stack is empty, print only a new line
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	(void)line_number;

	for (;ptr && (ptr->n > 0 && ptr->n <= 127) ; ptr = ptr->next)
	{
		if (ptr->n)
		printf("%c", ptr->n);
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * The top element of the stack becomes the last one
 * and the second top element of the stack
 * becomes the first one
 * @stack: pointer to stack
 * @line_number: position at opcode
 * rotl never fails
 * Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack)->next && (*stack)->next->next)
	{
		first = (*stack)->next;
		last = (*stack)->next;
		while (last->next != NULL)
			last = last->next;

		first->next->prev = *stack;
		(*stack)->next = first->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom
 * The last element of the stack
 * becomes the top element of the stack
 * @stack: pointer to stack
 * @line_number: position at opcode
 * rotl never fails
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if ((*stack)->next && (*stack)->next->next)
	{
		first = (*stack)->next;
		last = (*stack)->next;
		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		(*stack)->next = last;
		last->prev = *stack;
		last->next = first;
		first->prev = last;
	} 
}
