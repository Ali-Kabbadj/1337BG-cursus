/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:39:39 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/15 16:44:17 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_stack(t_stack **source, t_stack **dest)
{
    t_stack *dest_tmp;
    t_stack *source_tmp;

    source_tmp = *source;
    *source = source_tmp->next;
    dest_tmp = *dest;
    *dest = source_tmp;
    source_tmp->next = dest_tmp;
}

void do_pa(t_stack **stack_a, t_stack **stack_b)
{
    push_stack(stack_b, stack_a);
}

void do_pb(t_stack **stack_a, t_stack **stack_b)
{
    push_stack(stack_a, stack_b);
}

