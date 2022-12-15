#include "push_swap.h"

//function to set indexes
void set_stack_indexes(t_stack *stack)
{
    t_stack *tmp;
    t_stack *tmp1;

    tmp = stack;
    tmp1 = stack;
    while (tmp)
    {
        tmp1 = stack;
        while (tmp1)
        {
            if (tmp->value > tmp1->value)
                tmp->index = tmp->index + 1;
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
}

t_stack *initialize_stack(int argc, char **argv)
{
    int i;
    t_stack *stack_a;
    long int nb_value;
    
    i = 1;
    while (i < argc)
    {
        nb_value = atoi(argv[i]);
        if (nb_value > INT_MAX || nb_value < INT_MIN)
            exit_error(); //not yet implemented
        if (i == 1)
            stack_a = create_new_stack_node(nb_value);
        else
        {
            //needs refactoring
            set_stack_new_tail(&stack_a, create_new_stack_node(nb_value));
        }
        i++;
    }
    return (stack_a);
}