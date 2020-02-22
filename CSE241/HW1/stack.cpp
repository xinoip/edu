#include "./stack.h"

stack_t *newNode(Input d)
{
    stack_t *rtr = (stack_t *)malloc(sizeof(stack_t));
    rtr->data = d;
    rtr->next = NULL;
    return rtr;
}

void pushStack(stack_t **s, Input d)
{
    stack_t *node = newNode(d);
    node->next = *s;
    *s = node;
}

Input popStack(stack_t **s)
{
    if (isEmptyStack(*s))
        std::cout << "Can't pop empty stack!\n";
    stack_t *tmp = *s;
    *s = (*s)->next;
    Input popped = tmp->data;
    free(tmp);
    return popped;
}

Input peekStack(stack_t *s)
{
    if (s != NULL)
        return s->data;
    return Input::invalid;
}

bool isEmptyStack(stack_t *s)
{
    return !s;
}

void printStack(stack_t *s)
{
    while (s != NULL)
    {
        printInput(s->data);
        s = s->next;
        std::cout << " ";
    }
    std::cout << std::endl;
}

void resetStack(stack_t **s)
{
    while (!isEmptyStack(*s))
    {
        popStack(s);
    }
}