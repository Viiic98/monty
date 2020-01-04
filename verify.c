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
	if (isdigit(str[0]) != 0 || (str[0] == '-' && isdigit(str[1]) != 0))
		return (atoi(str));

	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
	close_program();
	exit(EXIT_FAILURE);
}
