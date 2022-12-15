/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:29:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/15 19:09:52 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverce_rotate_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *tail_precedent;

    tmp = *stack;
    tail = get_stack_tail(*stack);
    tail_precedent = get_stack_tail_precedent(*stack);
    tmp = *stack;
    *stack = tail;
    tail->next = tmp;
    tail_precedent->next = NULL;
}

void do_rra(t_stack **stack_a)
{
    reverce_rotate_stack(stack_a);
    write(1,"rra\n",4);
}

void do_rrb(t_stack **stack_b)
{
    reverce_rotate_stack(stack_b);
    write(1,"rrb\n",4);
}

void do_rrr(t_stack **stack_a, t_stack **stack_b)
{
    do_rra(stack_a);
    do_rrb(stack_b);
    write(1,"rrr\n",4);
}

