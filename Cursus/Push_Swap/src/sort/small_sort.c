/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:08:20 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:44:35 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort_utiles/sort_utiles.h"
#include <limits.h>

int	get_max_value_index(t_stack *stack)
{
	int		max_value;
	int		max_value_index;
	t_stack	*tmp;

	tmp = stack;
	max_value = INT_MIN;
	max_value_index = -1;
	while (tmp)
	{
		if (tmp->value > max_value)
		{
			max_value = tmp->value;
			max_value_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (max_value_index);
}

void	small_sort(t_stack **stack_a)
{
	int	max_value_index;

	max_value_index = get_max_value_index(*stack_a);
	if ((*stack_a)->index == max_value_index)
		do_ra(stack_a);
	else if (((*stack_a)->next)->index == max_value_index)
		do_rra(stack_a);
	if ((*stack_a)->index > ((*stack_a)->next)->index)
		do_sa(stack_a);
}
