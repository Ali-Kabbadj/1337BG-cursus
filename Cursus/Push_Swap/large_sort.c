/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:45:36 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/05 17:52:06 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push all from stack a to b exept three */
/*start by pushing smallest indexs as much as possible */
/*then push larger ones*/

void push_all_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    int stacksize;
    int i;
    int push_count;

    stacksize = get_stack_size(*stack_a);
    i = 0;
    push_count = 0;
    while (i < stacksize / 2 && stacksize > 6 && stacksize - push_count > 3)
    {
        /*to push smaller indexes first*/
        if ((*stack_a)->index < stacksize / 2)
        {
            do_pb(stack_a,stack_b);
            push_count++;
        }
        else
            do_ra(stack_a);
        i++;
    }
    while (stacksize - push_count > 3)
    {
        do_pb(stack_a, stack_b);
        push_count++;
    }
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

int get_target_pos(int b_index, int target_pos, t_stack **stack_a)
{
    t_stack *tmp_a;
    
    tmp_a = *stack_a;
    while (tmp_a->next)
    {
        if (tmp_a->index > b_index && target_pos <= INT_MAX)
        {
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    return (target_pos);
}

void large_sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    
    push_all_to_stack_b(stack_a, stack_b);
    tmp_b = *stack_b;
    set_pos(stack_a);
    set_pos(stack_b);
    while (tmp_b)
    {
        tmp_b->target_pos = get_target_pos(tmp_b->index, INT_MAX, stack_a);
        tmp_b = tmp_b->next;
    }
    
}
