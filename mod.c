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

/**
*add_node - create a new node
*@stack: stack pointer
*@p_new: pointer to new node
*Return: void
*/
void add_node(stack_t **stack, stack_t **p_new)
{
	stack_t *ptr;
	stack_t *new_p = (*p_new);

	if (stack_or_queue(*stack) == STACK)
	{
		ptr = (*stack)->next;
		new_p->next = ptr;
		new_p->prev = NULL;
		if (ptr != NULL)
		ptr->prev = new_p;
		(*stack)->next = new_p;
	}
	else if (stack_or_queue(*stack) == QUEUE)
	{
		ptr = (*stack);
		while (ptr)
		ptr = ptr->next;
		ptr->next = new_p;
		new_p->next = NULL;
		if (ptr)
		new_p->prev = ptr;
	}
}
