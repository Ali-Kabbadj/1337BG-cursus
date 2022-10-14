/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdrup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:42:23 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/14 03:42:49 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strdup(const char *s1)
{
    char *res;
    int slen;
    
    slen = ft_strlen(s1) + 1;
    res = (char *)malloc(slen * sizeof(char));
    if(!res)
        return (0);
    ft_memset(res,'\0',slen);
    return ((char*)ft_memmove(res,s1,slen));
}

// int main()
// {
//     const char *s1 = "hello world";
//     printf("%s\n",ft_strdup(s1));
//     printf("%s",strdup(s1));
// }