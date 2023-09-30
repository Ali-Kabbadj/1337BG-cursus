/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:33:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 13:00:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/error_handling/error_handling.h"
#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	validate_args(argc, argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (stack_a == NULL || stack_b == NULL)
		exit_program(stack_a, stack_b, 2);
	initialize_stack_a(argc, argv, stack_a, stack_b);
	set_stack_indexes(*stack_a);
	sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
