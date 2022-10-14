/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:36:22 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/14 05:36:22 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char *res;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    res = malloc(sizeof(char) * (ft_strlen(s1) - ft_strlen(set)));
    if(!res)
        return (0);
    while (s1[i])
    {
        if(s1[i] ! set[i])
            res[j++] = s1[i]; 
    }
    return (res);
}

// int main()
// {
//     char const *s1 = "1 abcd 1";
//     char const *set = " ";
//     printf("%s",ft_strtrim(s1,set)); 
// }