#include "monty.h"
/**
 * verify - Verify if str is an integer
 * @str: string
 * @ln: line number
 * Return: Integer if it success or print an error if it fails
 */
int verify(char *str, unsigned int ln)
{
	if (!str)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		return (isnum(str, ln));
	}
	return (0);
}
/**
 * isnum - Verify if str is a num
 * @str: string
 * @ln: line number
 * Return: String converted to int or print error if it fails
 */
int isnum(char *str, unsigned int ln)
{
	int i = 0, error = 0;

	if (!str)
		error = 1;

	if (str[i] == '-' || isdigit(str[i]))
		i++;
	while (str[i])
	{
		if (!isdigit(str[i++]))
		{
			error = 1;
			break;
		}
	}

	if (error)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	return (atoi(str));
}
