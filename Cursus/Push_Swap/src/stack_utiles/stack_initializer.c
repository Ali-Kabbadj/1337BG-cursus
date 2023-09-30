/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:45:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:19:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	initialize_stack_a(int argc, char **argv, t_stack **stack_a,
		t_stack **stack_b)
{
	int		*integers;
	size_t	nb_count;
	int		i;

	i = 0;
	nb_count = count_nb_integers(argc, argv);
	integers = (int *)malloc(sizeof(int) * (((int)nb_count)));
	if (integers == NULL)
	{
		free(integers);
		exit_program(stack_a, stack_b, 2);
	}
	to_int_array(argv, integers);
	while (i < (int)nb_count && integers)
	{
		if (i == 0)
			*stack_a = create_new_stack_node(integers[i]);
		else
			set_stack_new_tail(stack_a, create_new_stack_node(integers[i]));
		i++;
	}
	*stack_b = NULL;
	free(integers);
}
