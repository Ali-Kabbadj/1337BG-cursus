/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utiles.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:10:27 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/28 17:24:24 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILES_H
# define SORT_UTILES_H
# include "./../struct.h"
# include "./moves.h"

void	set_pos(t_stack **stack);
int		is_sorted(t_stack *stack);
void	set_stack_indexes(t_stack *stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	small_sort(t_stack **stack_a);
void	medium_sort(t_stack **stack_a, t_stack **stack_b);
void	large_sort(t_stack **stack_a, t_stack **stack_b);
#endif