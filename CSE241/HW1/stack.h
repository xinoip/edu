#ifndef Stack_h
#define Stack_h

#include <iostream>
#include <cstdlib>
#include "./input_enum.h"

/**
 * Stack node for holding [Input]
 */
typedef struct Stack
{
    Input data;
    struct Stack *next;
} stack_t;

/**
 * Allocate a new node for stack
 * 
 * @param d [Input] nodes data
 * @return [stack_t] created node
 */
stack_t *newNode(Input d);

/**
 * Push & Pop & Peek
 */
void pushStack(stack_t **s, Input d);
Input popStack(stack_t **s);
Input peekStack(stack_t *s);

/**
 * Some control flow things
 */
bool isEmptyStack(stack_t *s);
void printStack(stack_t *s);

/**
 * Free stack completely
 */
void resetStack(stack_t **s);

#endif