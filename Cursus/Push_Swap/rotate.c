/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:45:48 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/15 19:09:26 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    tmp = *stack;
    tail = get_stack_tail(*stack);
    *stack = (*stack)->next;
    tail->next = tmp;
    tmp->next = NULL;
}

void do_ra(t_stack **stack_a)
{
    rotate_stack(stack_a);
    write(1,"ra\n",3);
}

void do_rb(t_stack **stack_b)
{
    rotate_stack(stack_b);
    write(1,"sb\n",3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    do_ra(stack_a);
    do_rb(stack_b);
    write(1,"rr\n",3);
}