/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:45 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:27:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, const char *s2)
{
    char *res;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (0);
    res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!res)
        return (0);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while(s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    free(s1);
    return (res);
}