/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:25:01 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/08 13:02:41 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack)
{
    //to do
    (void)stack;
}

void exit_program(t_stack **stack_a, t_stack **stack_b, int error_id)
{
    if (stack_a == NULL || *stack_a)
        free_stack(stack_a);
    if (stack_b == NULL || *stack_b)
        free_stack(stack_b);
    ft_printf("ERROR : ");
    if (error_id == -1)
        ft_printf("%s\n", ARG_INVALID_MSSG);
    else if (error_id == -2)
        ft_printf("%s\n", DUPLICATE_DIGIT_MSSG);
    else if (error_id == -3)
        ft_printf("%s\n", INT_MIN_MAX_MSSG);
    else if (error_id == -4)
        ft_printf("%s\n", TOO_FEW_ARGS_MSSG);
    exit(0);
}