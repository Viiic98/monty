#include "monty.h"
/**
 * close_program - free all the elements in the buffer struct
 * Return: void
 */
void close_program()
{
    if (to_free.head)
    {
        _free(&to_free.head);
    }
	if (to_free.line)
        free(to_free.line);
	fclose(to_free.mf);
}