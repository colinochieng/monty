/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to stack
 * @line_number: position at opcode
 * rotl never fails
 * Return: void
*/
void stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;

	(void)line_number;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to stack
 * @line_number: position at opcode
 * rotl never fails
 * Return: void
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;

	(void)line_number;
}
