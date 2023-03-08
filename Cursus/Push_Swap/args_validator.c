/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:46:44 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/08 11:37:58 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_args(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (is_duplicate(argv[i], argc, argv, i))
            return(DUPLICATE_DIGIT_ID);
        else if (!is_integer(argv[i]))
            return (ARG_INVALID_ID);
        i++;
    }
    return (TRUE);
}

int is_duplicate(char *s ,int argc, char **argv, int s_index)
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        if (i != s_index && is_same_integer_str(s, argv[i]))
            return (TRUE);
        i++;
    }
    return (FALSE);
}