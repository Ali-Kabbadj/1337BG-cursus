#include "push_swap.h"

void program_error(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a != NULL)
        free_stack(stack_a);
    if (stack_b == NULL || *stack_b != NULL)
        free_stack(stack_b);
    write(2, "Error\n", 6);
    exit(1);
}

long int ft_atoi(const char *str)
{
    long int nb;
    int isneg;
    int i;

    nb = 0;
    isneg = 1;
    i = 0;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (is_digit(str[i]))
    {
        nb = (nb * 10) + (str[i] - '0');
        i++;
    }
    return (nb * isneg);
}