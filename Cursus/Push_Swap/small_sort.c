/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:12:01 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/15 18:59:14 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int get_max_index(t_stack *stack)
{
    t_stack *tmp;
    int max_index;

    tmp = stack;
    max_index = 0;
    while (tmp)
    {
        if (tmp->index > max_index)
            max_index = tmp->index;
        tmp = tmp->next;
    }
    return (max_index);
}

void small_sort(t_stack **stack_a)
{
    int max_index;

    max_index = get_max_index(*stack_a);
    if ((*stack_a)->index == max_index)
        do_ra(stack_a);
    else if (((*stack_a)->next)->index == max_index)
        do_rra(stack_a);
    if ((*stack_a)->index > ((*stack_a)->next)->index)
        do_sa(stack_a);
}