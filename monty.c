#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * main - program integration
 * @ac: number of vectors
 * @av: vectors
 * Return: status
*/
int main(int ac, char **av)
{
	FILE *fp = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	exit_status = read_monty(fp);
	fclose(fp);
	return (exit_status);
}
