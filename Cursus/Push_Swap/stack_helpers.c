#include "push_swap.h"

t_stack *create_new_stack_node(int value)
{
    t_stack *newnode;

    newnode = malloc(sizeof(t_stack));
    newnode->index = 0;
    newnode->next = NULL;
    newnode->pos = -1;
    newnode->target_pos = -1;
    newnode->value = value;
    return (newnode);
}

t_stack *get_stack_tail(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

t_stack *get_stack_tail_precedent(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
    {
        if ((tmp->next)->next == NULL)
            break;
        tmp = tmp->next;
    }
    return (tmp);
}

void set_stack_new_tail(t_stack **stack, t_stack *newtail)
{
    t_stack *tail;

    if (!stack || !(*stack))
        *stack = newtail;
    else
    {
        tail = get_stack_tail(*stack);
        tail->next = newtail;
    }
}

int get_stack_size(t_stack *stack)
{
    t_stack *tmp;
    int size;

    tmp = stack;
    size = 0;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

int is_sorted(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
    {
        if (tmp->value > (tmp->next)->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}