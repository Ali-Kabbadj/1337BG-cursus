/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:31:09 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:45:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/error_handling/error_handling.h"
#include "./../../includes/sort_utiles/sort_utiles.h"
#include "./../../includes/stack_utiles/stack_utiles.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stacksize;

	stacksize = get_stack_size(stack_a);
	if (is_sorted(*stack_a))
		exit_program(stack_a, stack_b, 0);
	if (stacksize == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stacksize == 3)
		small_sort(stack_a);
	else if (stacksize <= 5)
		medium_sort(stack_a, stack_b);
	else
		large_sort(stack_a, stack_b);
}
