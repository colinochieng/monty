#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define DELIMS " \t\n\r\a\b"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Stack Operation*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


/*Monty operation*/
int read_monty(FILE *stream);
int null_line(char *str, char *delim);
void free_token(char **tokens);
void (*get_function(char *opcode))(stack_t **, size_t);
void free_stack(stack_t *stack);

/**
 * struct track_words - operates words in string
 * @offset: position of at the string
 * @word_len: len of word;
*/
typedef struct track_words
{
	int offset;
	int word_len;
	char *word;
} track_w;

/* Tokenization */
int word_count(char *line, char *delim);
char **split(char *line, char *delim);
void words_len(track_w *ptr, char *line, char *delim);
int is_delim(char c, char *delim);

#endif /* MONTY_H */
