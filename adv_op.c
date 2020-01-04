#include "monty.h"
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
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		if (tail->next->n == 0)
		{
			dprintf(STDERR_FILENO, "L%d: division by zero\n", ln);
			close_program();
			exit(EXIT_FAILURE);
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
		close_program();
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
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next->next)
			tail = tail->next;
		if (tail->next->n == 0)
		{
			dprintf(STDERR_FILENO, "L%d: division by zero\n", ln);
			close_program();
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
		close_program();
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
