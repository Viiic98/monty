#include "monty.h"

buffers to_free = {
	NULL,
	NULL,
	NULL
};

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
	ssize_t r;
	size_t len = 0;
	char *op = NULL, *strval = NULL;
	int value;
	unsigned int ln = 1;

	to_free.mf = fopen(file, "r");
	if (!to_free.mf)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		r = getline(&to_free.line, &len, to_free.mf);
		while (r != -1)
		{
			op = strtok(to_free.line, " \n");
			if (op)
			{
				if (strcmp(op, "push") == 0)
				{
					strval = strtok(NULL, " \n");
					value = verify(strval, ln);
					exe_push(&to_free.head, value);
				}
				else if (op[0] != '#')
					monty_commands(&to_free.head, op, ln);
			}
			ln++;
			r = getline(&to_free.line, &len, to_free.mf);
		}
	}
	close_program();
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
