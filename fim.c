#include <stdio.h>
#include "monty.h"
/**
 * 
 * 
 * 
 */
int main(int ac, char **av, char **env)
{
    int fd;

    if (ac != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
}