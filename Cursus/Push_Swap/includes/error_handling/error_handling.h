/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:12:51 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:59:43 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "./../struct.h"

void	free_stacks(t_stack **stack_a, t_stack **stack_b);
void	exit_program(t_stack **stack_a, t_stack **stack_b, int error_id);

#endif