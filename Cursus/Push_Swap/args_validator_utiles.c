/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator_utiles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:58:26 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/08 11:04:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_same_integer_str(char *s1 , char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s1[i] && s2[j])
    {
        if (s1[i] == '+')
            i++;
        if (s2[j] == '+')
            j++;
        if (s1[i] == '-' && s2[j] == '-')
        {
            i++;
            j++;
        }
        if (ft_strcmp(&s1[i],&s2[j]) != 0)
            return(FALSE);
        i++;
        j++;
    }
    return (TRUE);
}

int is_integer(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '+' || s[i] == '-')
            i++;
        if (s[i] < '0' || s[i] > '9')
            return (FALSE);
        i++;
    }
    return (TRUE);
}
