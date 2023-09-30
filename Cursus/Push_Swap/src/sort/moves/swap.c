/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:03:15 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/28 11:47:23 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/push_swap.h"

static void	do_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = ((*stack)->next)->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	do_sa(t_stack **stack_a)
{
	do_swap(stack_a);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	do_swap(stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	write(1, "ss\n", 3);
}
