#include "push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack))
        return;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

t_stack *get_stack_tail(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp && tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

t_stack *get_stack_tail_precedent(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp && tmp->next && tmp->next->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

t_stack *create_new_stack_node(int nb_value)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = nb_value;
    new_node->index = 0;
    new_node->next = NULL;
    return (new_node);
}

void set_new_stack_tail(t_stack **stack, t_stack *new)
{
    t_stack *tail;

    if (!new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    tail = get_stack_tail(*stack);
    tail->next = new;
}

int get_stack_size(t_stack *stack)
{
    int size;
    t_stack *tmp;

    size = 0;
  
    if (!stack)
        return (0);
    tmp = stack;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}