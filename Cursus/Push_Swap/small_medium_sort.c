/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_medium_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:12:01 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/09 21:16:42 by akabbadj         ###   ########.fr       */
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

int get_next_min_index(t_stack *stack)
{
    int next_min_index;

    next_min_index = get_min_index(stack);
    return (next_min_index +  1);
}

int get_next_min_index_pos(t_stack *stack)
{
    t_stack *tmp;
    int     next_min_index;
    int     min_idx;

    tmp = stack;
    min_idx = get_min_index(stack);
    next_min_index = get_next_min_index(stack);
    while (tmp->next)
    {
        if (tmp->index == next_min_index)
        {
            return (tmp->pos);
        }
        tmp = tmp->next;
    }   
    return (0);
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
    return (get_stack_size(stack) - 1);
}

void get_closest_min_index_to_top(t_stack **stack)
{
    int move_amount;
    int stack_size;
    int min_index_pos;
    int next_min_idx_pos;
    
    stack_size = get_stack_size(*stack);
    min_index_pos = get_min_index_pos(*stack);
    next_min_idx_pos = get_next_min_index_pos(*stack);
    move_amount = stack_size - min_index_pos;
    if (next_min_idx_pos == 1 && min_index_pos > stack_size / 2) 
        do_sa(stack);
    if (min_index_pos <= get_stack_size(*stack) / 2)
    {
        if (min_index_pos == 1)
            do_sa(stack);
        else
            do_ra(stack);
    }
    else
        do_rra(stack);
}

// void get_closest_min_index_to_top(t_stack **stack)
// {
//     int move_amount;
//     int stack_size;
//     int min_index_pos;
//     int next_min_idx_pos;
    
//     stack_size = get_stack_size(*stack);
//     min_index_pos = get_min_index_pos(*stack);
//     next_min_idx_pos = get_next_min_index_pos(*stack);
//     move_amount = stack_size - min_index_pos;
//     if (next_min_idx_pos == 1 && min_index_pos > stack_size / 2) 
//         do_sa(stack);
//     if (min_index_pos <= get_stack_size(*stack) / 5)
//     {
//         if (min_index_pos == 1)
//             do_sa(stack);
//         else
//             do_ra(stack);
//     }
//     else
//         do_rra(stack);
// }


void medium_sort(t_stack **stack_a, t_stack **stack_b)
{
    while (get_stack_size(*stack_a) > 3)
    {
        set_pos(stack_a);
        if ((*stack_a)->index ==  get_min_index(*stack_a) && (*stack_a)->index <= get_stack_size(*stack_a) / 2)
            do_pb(stack_a,stack_b);
        else
            get_closest_min_index_to_top(stack_a);
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