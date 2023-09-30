/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:48:27 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 16:19:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/push_swap.h"

void	reverce_rotate_stack(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*tail;
	t_stack	*tail_prev;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	tail = get_stack_tail(*stack);
	tail_prev = tail->prev;
	tail->prev = NULL;
	tail->next = first_node;
	first_node->prev = tail;
	tail_prev->next = NULL;
	*stack = tail;
}

void	do_rra(t_stack **stack_a)
{
	reverce_rotate_stack(stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack)
{
	reverce_rotate_stack(stack);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
	write(1, "rrr\n", 4);
}
