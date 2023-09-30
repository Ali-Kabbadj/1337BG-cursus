/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:59:57 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:59:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (stack_a)
	{
		tmp = *stack_a;
		while (tmp)
		{
			tmp = tmp->next;
			free(*stack_a);
			*stack_a = tmp;
		}
		free(stack_a);
	}
	if (stack_b)
	{
		tmp = *stack_b;
		while (tmp)
		{
			tmp = tmp->next;
			free(*stack_b);
			*stack_b = tmp;
		}
		free(stack_b);
	}
}

void	exit_program(t_stack **stack_a, t_stack **stack_b, int error_id)
{
	if (error_id == 2)
		write(2, "Error\n", 6);
	free_stacks(stack_a, stack_b);
	exit(error_id);
}
