/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:57:46 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 13:07:53 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/sort_utiles/sort_utiles.h"
#include "./../../includes/stack_utiles/stack_utiles.h"
#include <limits.h>

t_stack	*find_next_min(t_stack **stack, t_stack *current_min)
{
	t_stack	*tmp;
	t_stack	*next_min;

	tmp = *stack;
	next_min = NULL;
	while (tmp)
	{
		if (tmp->value > current_min->value)
		{
			if (next_min == NULL)
				next_min = tmp;
			else if (tmp->value < next_min->value)
				next_min = tmp;
		}
		tmp = tmp->next;
	}
	return (next_min);
}

int	get_min_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		min_value;
	int		min_pos;

	tmp = stack;
	min_value = INT_MAX;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

void	move_current_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	stacksize;

	set_pos(stack_a);
	min_pos = get_min_pos(*stack_a);
	stacksize = get_stack_size(stack_a);
	if (min_pos <= stacksize / 2)
	{
		while ((*stack_a)->pos != min_pos)
			do_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->pos != min_pos)
			do_rra(stack_a);
	}
	do_pb(stack_a, stack_b);
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(stack_a) > 3 && !is_sorted(*stack_a))
		move_current_min_to_b(stack_a, stack_b);
	small_sort(stack_a);
	while (get_stack_size(stack_b) > 0)
		do_pa(stack_a, stack_b);
}
