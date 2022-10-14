/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:03:19 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/14 04:03:19 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    //add condition for when start >= ft_strlen(s)
    size_t i;
    char *res;
    size_t slen;
     
    i = 0;
    slen = ft_strlen(s);
    res = malloc(sizeof(char)*(len + 1));
    if(!res || start >= slen)
        return (0);
    ft_memset(res,'\0', len + 1);
    ft_memmove(res, (const char *)s + start, len);
    return (res);
}

// int main()
// {
//     char *s = "Hello-The substring";
//     printf("%s",ft_substr(s,6,13));
// }