/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator_utiles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:58:26 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/16 07:42:27 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int nbstrcmp(char *s1 , char *s2)
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
        if (s1[i] != s2[j])
          return (1);
        i++;
        j++;
    }
    return (0);
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
            return (0);
        i++;
    }
    return (1);
}
