#include "monty.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * null_line - checks if is made up of
 * only delimiters
 * @str: pointer to line
 * @delim: delimiters
 * Return: 0 or 1
*/
int null_line(char *str, char *delim)
{
	int i = 0;

	for (i = 0; str[i]; i++)
	{
		if (!(is_delim(str[i], delim)))
		return (0);
	}
	return (1);
}

/**
 * free_token - frees opcode token
 * @tokens: opcode generated tokens
 * Return: void
*/
void free_token(char **tokens)
{
	int i;

	if (tokens != NULL)
	{
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
		free(tokens);
	}
}

/**
 * free_stack - frees stack_t
 * @stack: stack pointer
 * Return: void
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}


/**
 * get_function - finds corresponding function
 * @opcode: command
 * Return: corresponding function
*/
void (*get_function(char *opcode))(stack_t **, unsigned int)
{
	int i;
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_monty},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(funcs[i].opcode, opcode) == 0)
		return (funcs[i].f);
	}
	return (NULL);
}
