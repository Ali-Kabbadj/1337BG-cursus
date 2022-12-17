/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:25:01 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/16 07:35:40 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack)
{
    
}
void exit_program(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a)
        free_stack(stack_a);
    if (stack_b == NULL || *stack_b)
        free_stack(stack_b);
    write(2,"Error\n",6);
    exit(1);
}