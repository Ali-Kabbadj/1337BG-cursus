/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:24:50 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 13:07:34 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/sort_utiles/large_sort_utiles.h"
#include "./../../includes/sort_utiles/sort_utiles.h"
#include "./../../includes/stack_utiles/stack_utiles.h"

int	determine_chucksize(t_stack **stack_a, int stacksize)
{
	int	chunck_size;

	chunck_size = 0;
	if (stacksize <= 20)
		chunck_size = 2;
	else if (stacksize <= 100)
		chunck_size = (stacksize / 7);
	else
		chunck_size = (stacksize / 12);
	return (chunck_size);
}

int	max_is_in_top_chunk(t_stack **stack, int chunk_top_left)
{
	int		max;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	max = get_max(*stack);
	while (i < chunk_top_left)
	{
		if (tmp->value == max)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	traverse_back_to_be(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	static int	moves;
	int			max;
	int			chunk_top_left;

	max = get_max(*stack_b);
	chunk_top_left = chunk_size;
	if (max_is_in_top_chunk(stack_b, chunk_top_left))
	{
		while ((*stack_b)->value != max)
		{
			do_rb(stack_b);
			moves++;
			chunk_top_left--;
		}
		do_pa(stack_a, stack_b);
		if (get_stack_size(stack_b))
			traverse_back_to_be(stack_a, stack_b, chunk_size);
	}
	else
	{
		while ((*stack_b)->value != max && moves--)
			do_rrb(stack_b);
		do_pa(stack_a, stack_b);
	}
	return (0);
}

void	large_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stacksize;
	int	chunck_size;
	int	chunk_count;
	int	*chunk_min_max;

	stacksize = get_stack_size(stack_a);
	chunck_size = determine_chucksize(stack_a, stacksize);
	chunk_count = (stacksize / chunck_size) + 1;
	chunk_min_max = malloc(sizeof(int) * 2);
	chunk_min_max[0] = 0;
	chunk_min_max[1] = 0;
	while (chunk_count && get_stack_size(stack_a))
	{
		chunk_min_max[0] = get_min(*stack_a);
		if (chunck_size == get_stack_size(stack_a))
			chunk_min_max[1] = get_max(*stack_a);
		else
			chunk_min_max[1] = find_chunk_max(stack_a, chunk_min_max[0],
					chunck_size - 1);
		move_chunk_to_b(stack_a, stack_b, chunk_min_max, chunck_size);
		chunk_count--;
	}
	while (get_stack_size(stack_b))
		traverse_back_to_be(stack_a, stack_b, chunck_size);
	free(chunk_min_max);
}
