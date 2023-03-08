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

static int it_out_of_int_range(char *s)
{
    char    *min;
    char    *max;

    min = ft_itoa(INT_MIN);
    max = ft_itoa(INT_MAX);
    if (( ft_strlen(s) >= 11 && ft_strcmp(min, s) < 0) || ( ft_strlen(s) >= 10 && ft_strcmp(max, s) < 0))
        return (1);
    free(min);
    free(max);
    return (0);
}

t_stack *initialize_stack(int argc, char **argv)
{
    int i;
    t_stack *stack_a;
    int nb_value;
    
    i = 1;
    nb_value = 0;
    while (i < argc)
    {
        if (it_out_of_int_range(argv[i]))
            exit_program(&stack_a, NULL, -3);
        nb_value = ft_atoi(argv[i]);
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