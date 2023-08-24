#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void error(char *av);
void usage(void);
void malloc_error(void);
void print_token(char **token);
void free_tokens(char **tokens);
char **_strtok(char *buffer);


void pall(void);
int push(int line, FILE *file, char *buffer, char **strings);
int pint(int line, FILE *file, char *buffer, char **strings);
int pop(int line, FILE *file, char *buffer, char **strings);
int swap(int line, FILE *file, char *buffer, char **strings);
int add(int line, FILE *file, char *buffer, char **strings);
void nop(void);
void cleanup(FILE *file, char *buffer, char **strings);
int sub(int line, FILE *file, char *buffer, char **strings);
int execute(char **strings);


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(int line, FILE *file, char *buffer, char **strings);
} instruction_t;


/**
 * struct code - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFI
 *
 */

typedef struct code
{
	char *op;
	void (*func)(void);
} code;

extern stack_t *head;
void execute_instructions(int line, FILE *file, char *buffer, char **strings);
#endif
