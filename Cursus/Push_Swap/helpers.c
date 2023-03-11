#include "push_swap.h"


int char_is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

void set_pos(t_stack **stack)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

int ft_atoi(const char *s)
{
    int i;
    int sign;
    long int nb;

    i = 0;
    sign = 1;
    nb = 0;
    if (s[i] == '+')
        i++;
    else if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (s[i] && char_is_digit(s[i]))
    {
        nb = nb * 10 + (s[i] - '0');
        i++;
    }
    return (nb * sign);
}