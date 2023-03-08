/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_medium_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:12:01 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/08 18:49:25 by akabbadj         ###   ########.fr       */
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

int get_min_index(t_stack *stack)
{
    t_stack *tmp;
    int min_index;

    tmp = stack;
    min_index = get_max_index(stack);
    while (tmp)
    {
        if (tmp->index < min_index)
            min_index = tmp->index;
        tmp = tmp->next;
    }
    return (min_index);
}

int get_min_index_pos(t_stack *stack)
{
    t_stack *tmp;
    int     min_index;

    tmp = stack;
    min_index = get_min_index(stack);
    while (tmp->next)
    {
        if (tmp->index == min_index)
            return (tmp->pos);
        tmp = tmp->next;
    }
    return (0);
}

void get_closest_min_index_to_top(t_stack **stack)
{
    t_stack **tmp;
    int move_amount;
    int stack_size;
    int min_index_pos;
    
    stack_size = get_stack_size(*stack);
    min_index_pos = get_min_index_pos(*stack);
    move_amount = stack_size - min_index_pos;
    
    if (min_index_pos <= 2)
    {
        while (move_amount > -1)
        {
            do_ra(stack);
            move_amount--;
        }
    }
    else 
    {
        while (move_amount > -1)
        {
            do_rra(stack);
            move_amount--;
        }
    }
    tmp = stack;
    
    
}

void medium_sort(t_stack **stack_a, t_stack **stack_b)
{
    while (get_stack_size(*stack_a) > 3)
    {
        set_pos(stack_a);
        if ((*stack_a)->index ==  get_min_index(*stack_a) && (*stack_a)->index <= 2)
            do_pb(stack_a,stack_b);
        else
        {
            // if ((*stack_a)->next != NULL && (*stack_a)->next->index == get_min_index((*stack_a)->next) && (*stack_a)->next->index <= 2)
            //     do_sa(stack_a);
            // else
            //     do_ra(stack_a);
            get_closest_min_index_to_top(stack_a);
        }
    }
    small_sort(stack_a);
    while (get_stack_size(*stack_b) > 0)
       do_pa(stack_a,stack_b);
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