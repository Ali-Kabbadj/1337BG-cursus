/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:04:45 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:49:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/push_swap.h"

t_stack	*create_new_stack_node(int value)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	newnode->value = value;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->pos = -1;
	newnode->index = -1;
	return (newnode);
}

t_stack	*get_stack_tail(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*get_stack_tail_precedent(t_stack *stack)
{
	return (get_stack_tail(stack)->prev);
}

void	set_stack_new_tail(t_stack **stack, t_stack *newtail)
{
	t_stack	*old_tail;

	old_tail = get_stack_tail(*stack);
	newtail->prev = old_tail;
	old_tail->next = newtail;
	(*stack)->prev = newtail;
}

int	get_stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
