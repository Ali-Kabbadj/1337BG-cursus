/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utiles.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:11:33 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/29 20:12:47 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGE_SORT_UTILES_H
# define LARGE_SORT_UTILES_H

# include "./../struct.h"

int		count_ra_moves(t_stack **stack_a, int chunk_start, int chunk_end);
int		count_rra_moves(t_stack **stack_a, int chunk_start, int chunk_end);
void	move_closest_to_top(t_stack **stack_a, int stacksize, int chunk_start,
			int chunk_end);
void	move_chunk_to_b(t_stack **stack_a, t_stack **stack_b,
			int *chunk_min_max, int chunk_size);
int		find_chunk_max(t_stack **stack_a, int chunk_start, int chunk_size);
#endif