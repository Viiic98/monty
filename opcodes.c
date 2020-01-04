#include "monty.h"
/**
 * monty_commands - Execute the monty command
 * @stack: pointer to stack
 * @op: opcode
 * @ln: line number
 * Return: Nothing, just call a function
 */
void monty_commands(stack_t **stack, char *op, unsigned int ln)
{
	int i = 0;
	instruction_t instructs[] = {
		{"pall", exe_pall},
		{"pint", exe_pint},
		{"pop", exe_pop},
		{"swap", exe_swap},
		{"add", exe_add},
		{"sub", exe_sub},
		{"div", exe_div},
		{"mul", exe_mul},
		{"mod", exe_mod},
		{NULL, NULL}
	};
	if (!stack && ln == 400)
		return;
	op = strtok(op, " \n");
	while (instructs[i].opcode)
	{
		if (strcmp(op, "nop") == 0)
			break;
		else if (strcmp(instructs[i].opcode, op) == 0)
		{
			instructs[i].f(stack, ln);
			break;
		}
		i++;
	}

	if (!instructs[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", ln, op);
		close_program();
		exit(EXIT_FAILURE);
	}
}
/**
 * exe_push - Insert a new node in the stack
 * @stack: pointer to stack
 * @value: value that will be inserted in the new node
 * Return: pointer to new node
 */
stack_t *exe_push(stack_t **stack, int value)
{
	stack_t *new, *tail = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		close_program();
		exit(EXIT_FAILURE);
	}
	new->n = value;
	if (!tail)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		new->prev = tail;
		new->next = NULL;
		tail->next = new;
	}
	return (new);
}
