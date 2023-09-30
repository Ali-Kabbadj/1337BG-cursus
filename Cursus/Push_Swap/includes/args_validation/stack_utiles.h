/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utiles.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:06:14 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 21:08:55 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILES_H
# define STACK_UTILES_H

# include "./../struct.h"
# include <stdlib.h>

void	exit_programalize_stack_a(int argc, char **argv, t_stack **stack_a,
			t_stack **stack_b);
t_stack	*create_new_stack_node(int value);
t_stack	*get_stack_tail(t_stack *stack);
t_stack	*get_stack_tail_precedent(t_stack *stack);
void	set_stack_new_tail(t_stack **stack, t_stack *newtail);
int		get_stack_size(t_stack **stack);
size_t	count_nb_integers(int argc, char **argv);
size_t	count_nb_integers(int argc, char **argv);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
#endif