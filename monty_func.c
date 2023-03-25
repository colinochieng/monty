#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	(void)line_number;

	if (ptr == NULL)
	{
		tok_track = true;
		handle_error2(POP, &exit_status);
		return;
	}

	if (ptr->next != NULL)
		ptr->next->prev = *stack;
	(*stack)->next = ptr->next;
	free(ptr);
}
/**
 * stack_or_queue - check if stack or queue
 * @stack: pointer to stack
 * Return: 0, 1 or -1
*/
int stack_or_queue(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);

	return (-1);
}

/**
 * push - pushes an element to the stack
 * element added at the beginning
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		tok_track = true;
		handle_error(MALLOC, &exit_status);
		return;
	}
	if (opcodes[1] == NULL)
	{
		free(new);
		handle_error(NO_INT, &exit_status);
		return;
	}

	for (i = 0; opcodes[1][i]; i++)
	{
		if (opcodes[1][i] == '-' && i == 0)
			continue;
		if (opcodes[1][i] < '0' || opcodes[1][i] > '9')
		{
			free(new);
			tok_track = true;
			handle_error(NO_INT, &exit_status);
			free_token(opcodes);
			return;
		}
	}
	new->n = atoi(opcodes[1]);
	new->next = NULL;
	new->prev = NULL;

	add_node(stack, &new);

	(void)line_number;
}

/**
 * pall - prints all the values on the stack
 *  starting from the top of the stack
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = (*stack)->next;

	(void) line_number;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 *  followed by a new line.
 * @stack: pointer to stack
 * @line_number: position at opcode
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack)->next == NULL)
	{
		tok_track = true;
		handle_error(STACK_EM, &exit_status);
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
