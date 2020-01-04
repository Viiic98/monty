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
		{"nop", NULL},
		{NULL, NULL}
	};
	if (!stack && ln == 400)
		return;
	op = strtok(op, " \n");
	while (instructs[i].opcode)
	{
		if (strcmp(instructs[i].opcode, "nop") == 0)
			break;
		else if (strcmp(instructs[i].opcode, op) == 0)
		{
			instructs[i].f(stack, ln);
		}
		i++;
	}
}
/**
 * exe_mod - computes the rest of the division
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just find the modul
 */
void exe_mod(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		if (tail->next->n == 0)
		{
			dprintf(STDERR_FILENO, "L%d: division by zero", ln);
		}
		tail->n %= tail->next->n;
		exe_pop(stack, ln);
	}

}
/**
 * exe_mul - multiplies the second top element with the top element
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just multiplies
 */
void exe_mul(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		tail->n *= tail->next->n;
		exe_pop(stack, ln);
	}

}
/**
 * exe_div - divides the second top element of the stack by the top element
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just div
 */
void exe_div(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		if (tail->next->n == 0)
		{
			dprintf(STDERR_FILENO, "L%d: division by zero\n", ln);
			exit(EXIT_FAILURE);
		}
		tail->n /= tail->next->n;
		exe_pop(stack, ln);
	}

}
/**
 * exe_sub - subtracts the top element of the stack from the second
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just sub
 */
void exe_sub(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		tail->n -= tail->next->n;
		exe_pop(stack, ln);
	}

}
/**
 * exe_add - Add the top two elements
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just add
 */
void exe_add(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		tail->n += tail->next->n;
		exe_pop(stack, ln);
	}

}
/**
 * exe_swap - swaps the top two elements
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just swap
 */
void exe_swap(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;
	int tmp;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		tmp = tail->n;
		tail->n = tail->prev->n;
		tail->prev->n = tmp;
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
		exit(EXIT_FAILURE);
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
/**
 * exe_pall - Print all the stack values
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just print the values
 */
void exe_pall(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	if (!tmp)
		return;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (tmp->prev)
		{
			dprintf(STDOUT_FILENO, "%d\n", tmp->n);
			tmp = tmp->prev;
		}
	}
	dprintf(STDOUT_FILENO, "%d\n", tmp->n);
	if (ln == 123)
		return;
}
/**
 * exe_pint - Print the value at the top of the stack
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just print the top value
 */
void exe_pint(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		dprintf(STDOUT_FILENO, "%d\n", tail->n);
	}
}
/**
 * exe_pop - remove the top element of the stack
 * @stack: pointer to stack
 * @ln: line number
 * Return: Nothing, just remove
 */
void exe_pop(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack", ln);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		if (!tail->prev)
		{
			free(tail);
			*stack = NULL;
		}
		else
		{
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
	}
}
