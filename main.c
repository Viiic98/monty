#include "monty.h"
/**
 * main - monty file interpreter
 * @ac: Number of arguments
 * @av: arguments
 * Return: 0 if it successfully
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		rfile(av[1]);
	return (0);
}
/**
 * rfile - Open and read the file
 * @file: name of file
 * Return: Nothing
 */
void rfile(char *file)
{
	ssize_t r = 0;
	size_t len = 0;
	char *op, *line, *strval;
	int value;
	unsigned int ln = 1;
	FILE *mf;
	stack_t *head = NULL;

	mf = fopen(file, "r");
	if (!mf)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		r = getline(&line, &len, mf);
		while (r != -1)
		{
			op = strtok(line, " \n");
			if (strcmp(op, "push") == 0)
			{
				strval = strtok(NULL, " \n");
				value = verify(strval, ln);
				exe_push(&head, value);
			}
			else if (op[0] != '#')
				monty_commands(&head, op, ln);
			ln++;
			r = getline(&line, &len, mf);
		}
	}
	_free(&head);
	free(op);
	fclose(mf);
}
/**
 * _free - frees the stack
 * @stack: pointer to stack
 * Return: nothing, just frees
 */
void _free(stack_t **stack)
{
	stack_t *tail = *stack;

	if (!tail)
		return;
	while (tail->next)
		tail = tail->next;
	while (tail->prev)
	{
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
	free(tail);
	*stack = NULL;
}
