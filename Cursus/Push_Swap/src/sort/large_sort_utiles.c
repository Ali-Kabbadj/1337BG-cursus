/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:08:51 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 20:20:54 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/sort_utiles/sort_utiles.h"
#include "./../../includes/stack_utiles/stack_utiles.h"

int	count_ra_moves(t_stack **stack_a, int chunk_start, int chunk_end)
{
	int		stacksize;
	int		med;
	int		count_from_top;
	t_stack	*temp;

	stacksize = get_stack_size(stack_a);
	med = stacksize;
	count_from_top = 0;
	temp = *stack_a;
	while (med)
	{
		if (temp->value >= chunk_start && temp->value <= chunk_end)
			break ;
		count_from_top++;
		temp = temp->next;
		if (!temp)
			break ;
		med--;
	}
	return (count_from_top);
}

int	count_rra_moves(t_stack **stack_a, int chunk_start, int chunk_end)
{
	int		stacksize;
	int		med;
	int		count_from_bottom;
	t_stack	*temp;

	stacksize = get_stack_size(stack_a);
	med = stacksize / 2;
	count_from_bottom = 1;
	temp = get_stack_tail(*stack_a);
	while (med && temp)
	{
		if (temp->value >= chunk_start && temp->value <= chunk_end)
			break ;
		count_from_bottom++;
		temp = temp->prev;
		med--;
	}
	return (count_from_bottom);
}

void	move_closest_to_top(t_stack **stack_a, int stacksize, int chunk_start,
		int chunk_end)
{
	int	count_from_top;
	int	count_from_bottom;

	stacksize = get_stack_size(stack_a);
	count_from_top = count_ra_moves(stack_a, chunk_start, chunk_end);
	count_from_bottom = count_rra_moves(stack_a, chunk_start, chunk_end);
	if (count_from_top > count_from_bottom)
	{
		while (count_from_bottom)
		{
			do_rra(stack_a);
			count_from_bottom--;
		}
	}
	else if (count_from_bottom >= count_from_top)
	{
		while (count_from_top)
		{
			do_ra(stack_a);
			count_from_top--;
		}
	}
}

void	move_chunk_to_b(t_stack **stack_a, t_stack **stack_b,
		int *chunk_min_max, int chunk_size)
{
	while (chunk_size && get_stack_size(stack_a))
	{
		move_closest_to_top(stack_a, get_stack_size(stack_a), chunk_min_max[0],
			chunk_min_max[1]);
		do_pb(stack_a, stack_b);
		chunk_size--;
	}
}

int	find_chunk_max(t_stack **stack_a, int chunk_start, int chunk_size)
{
	t_stack	*tmp;
	int		above_start;
	int		chunk_end;

	above_start = 1;
	chunk_end = 0;
	if (chunk_size > get_stack_size(stack_a))
		chunk_size = get_stack_size(stack_a);
	if (chunk_size == get_stack_size(stack_a))
		return (get_max(*stack_a));
	while (chunk_size)
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->value == chunk_start + above_start)
			{
				chunk_end = tmp->value;
				chunk_size--;
			}
			tmp = tmp->next;
		}
		above_start++;
	}
	return (chunk_end);
}
