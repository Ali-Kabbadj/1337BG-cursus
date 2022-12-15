#include "push_swap.h"

t_stack *initialize_stack_a(int argc, char **argv)
{
    t_stack *stack_a;
    long int nb_value;
    int i;

    stack_a = NULL;
    nb_value = 0;
    i = 1;
    while (i < argc)
    {
        nb_value = ft_atoi(argv[i]);
        if(nb_value > INT_MAX || nb_value < INT_MIN)
            program_error(&stack_a, NULL);
        if (i = 1)
            stack_a = stack_new((int)nb_value);
        else
            stack_add_bottom(&stack_a, stack_new((int)nb_value));
        i++;
    }
    return (stack_a);
}

void assign_index(t_stack *stack_a, int stack_size)
{
    t_stack *ptr;
    t_stack *highest;
    int value;

    while (--stack_size > 0)
    {
        ptr = stack_a;
        value = INT_MIN;
        highest = NULL;
        while (ptr)
        {
            if (ptr->value == INT_MIN && ptr->index == 0)
                ptr->index = 1;
            if (ptr->value > value && ptr->index == 0)
            {
                value = ptr->value;
                highest = ptr;
                ptr = stack_a;
            }
            else
                ptr = ptr->next;
        }
        if (highest != NULL)
            highest->index = stack_size;
    }
}