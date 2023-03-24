#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * is_delim - checks for delimter
 * @c: character
 * @delim: delimiters
 * Return: 1 or 0
*/
int is_delim(char c, char *delim)
{
	int i;

	for (i = 0; delim[i]; i++)
	{
		if (c == delim[i])
		return (1);
	}

	return (0);
}

/**
 * word_count - counts words in a line
 * @line: a line from monty opcode
 * @delim: delimiters
 * Return: word count
*/
int word_count(char *line, char *delim)
{
	int count = 0, flag = 1, i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (is_delim(line[i], delim))
		{
			flag = 1;
		}
		else if (flag)
		{
			flag = 0;
			count++;
		}
	}

	return (count);
}

/**
 * words_len - fills struct track_w
 * @ptr: pointer to track_w data type
 * @line: line read
 * @delim: delimiters
 *
 * Return: void
*/
void words_len(track_w *ptr, char *line, char *delim)
{
	int i, j, k;
	char c;

	if (ptr == NULL)
		return;

	for (; line[ptr->offset]; ptr->offset++)
	{
		c = line[ptr->offset];
		for (j = 0; delim[j]; j++)
		{
			if (c == delim[j])
				break;
		}
		if (!delim[j])
			break;
	}
	k = ptr->offset;

	for (i = 0; line[ptr->offset]; ptr->offset++, i++)
	{
		if (is_delim(line[ptr->offset], delim))
			break;
	}
	ptr->word_len = i;
	ptr->word = malloc(sizeof(char) * (i + 1));

	for (j = 0; k < ptr->offset; k++, j++)
		ptr->word[j] = line[k];
	ptr->word[j] = '\0';

}

/**
 * split - parses the line
 * @line: opcode line
 * @delim: delimiters
 * Return: token opcodes 
*/
char **split(char *line, char *delim)
{
	char **tokens = NULL;
	int token_count, i, j;
	track_w words;

	if (line[0] == '\0' && line == NULL)
		return (NULL);
	token_count = word_count(line, delim);
	words.offset = 0;

	if (token_count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (token_count + 1));

	if (tokens == NULL)
		return (NULL);

	for (i = 0; i < token_count; i++)
	{
		words_len(&words, line, delim); 
		tokens[i] = malloc(sizeof(char) * (words.word_len + 1));

		if (tokens[i] == NULL)
		{
			for(; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}

		for (j = 0; j < words.word_len; j++)
			tokens[i][j] = words.word[j];
		tokens[i][j] = '\0';
		free(words.word);
		}
		tokens[i] = NULL;
		return (tokens);
}
