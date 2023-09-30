/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:02:02 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 16:41:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	tail = get_stack_tail(*stack);
	first_node->prev = tail;
	first_node->next = NULL;
	tail->next = first_node;
	second_node->prev = NULL;
	*stack = second_node;
}

void	do_ra(t_stack **stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack **stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	write(1, "rr\n", 3);
}
