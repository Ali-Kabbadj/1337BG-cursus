/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:46:44 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/16 08:11:04 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int is_valid_args(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (is_duplicate(argv[i], argc, argv, i)  || !is_integer(argv[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_duplicate(char *s ,int argc, char **argv, int s_index)
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        if (i != s_index && !nbstrcmp(s, argv[i]))
            return (1);
        i++;
    }
    return (0);
}