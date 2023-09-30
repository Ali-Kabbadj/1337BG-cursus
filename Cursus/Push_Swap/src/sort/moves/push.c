/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:05:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 18:33:19 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/push_swap.h"

void	push_stack(t_stack **source, t_stack **dest)
{
	t_stack	*source_first;
	t_stack	*source_second;
	t_stack	*dest_first;

	if (!*source)
		return ;
	source_first = *source;
	source_second = source_first->next;
	if (dest && *dest)
	{
		dest_first = *dest;
		dest_first->prev = source_first;
		*source = source_second;
		source_first->next = dest_first;
	}
	else
	{
		*source = source_second;
		source_first->next = NULL;
	}
	if (source_second)
		source_second->prev = NULL;
	*dest = source_first;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}
