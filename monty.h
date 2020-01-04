#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct buffers
{
        FILE *mf;
        stack_t *head;
        char *line;
} buffers;

extern buffers to_free;
void close_program(void);

/* Functions */
void rfile(char*);
stack_t *exe_push(stack_t **, int);
void exe_pall(stack_t **, unsigned int);
void monty_commands(stack_t **, char *, unsigned int);
void exe_pint(stack_t **, unsigned int);
void exe_pop(stack_t **, unsigned int);
void exe_swap(stack_t **, unsigned int);
void exe_add(stack_t **, unsigned int);
void exe_sub(stack_t **, unsigned int);
void exe_div(stack_t **, unsigned int);
void exe_mul(stack_t **, unsigned int);
void exe_mod(stack_t **, unsigned int);
int verify(char *, unsigned int);
int isnum(char *, unsigned int);
void _free(stack_t **);
#endif
