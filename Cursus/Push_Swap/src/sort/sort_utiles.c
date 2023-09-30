/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:12:44 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 18:40:23 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global_macros.h"
#include "../../includes/sort_utiles/sort_utiles.h"
#include "../../includes/stack_utiles/stack_utiles.h"
#include "../../includes/struct.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next && tmp->value > (tmp->next)->value)
			return (FALSE);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (TRUE);
}

void	set_pos(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_stack_indexes(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = stack;
	tmp1 = stack;
	while (tmp)
	{
		tmp1 = stack;
		while (tmp1)
		{
			if (tmp->value > tmp1->value)
				tmp->index = tmp->index + 1;
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
