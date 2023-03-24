#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *ptr = (*stack)->next;

	if (ptr == NULL || ptr->next == NULL)
	{
		handle_error(SWAP, &exit_status);
		return;
	}

	temp = ptr->next;
	ptr->next = temp->next;
	ptr->prev = temp;
	if (temp->next)
	temp->next->prev = ptr;
	temp->next = ptr;
	temp->prev = *stack;
	(*stack)->next = ptr;

	(void)line_number;
}

/**
 * add - adds the top two elements of the stack
 * followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	if (ptr == NULL || ptr->next == NULL)
	{
		handle_error(ADD, &exit_status);
		return;
	}

	ptr->next->n += ptr->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack
 * followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;
	if (ptr == NULL || ptr->next == NULL)
	{
		handle_error(SUB, &exit_status);
		return;
	}

	ptr->next->n -= ptr->n;
	pop(stack, line_number);
}

/**
 * div - divides the second top element
 * of the stack by the top element of the stack
 * If the top element of the stack is 0 
 *      generates zero error
 * from the second top element of the stack
 * followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void div(stack_t **stack, unsigned int line_number)
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

	ptr->next->n /= ptr->n;
	pop(stack, line_number);
}
