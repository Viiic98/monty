#include "monty.h"
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
	if (ln > 1)
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
