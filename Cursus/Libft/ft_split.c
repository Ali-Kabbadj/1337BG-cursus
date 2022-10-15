/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 06:02:09 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/14 06:02:09 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char **ft_split(char const *s, char c)
{
    char **res;
    size_t s1len;
    size_t s2len;

    s1len = 0;
    s2len = 0;
    while (s[s1len] && s[s1len] != c)
        s1len++;
    s2len = ft_strlen(s + s1len + 1) + 1;
    res = malloc(sizeof(char*) * (s1len * s2len));
    if(!res)
        return (0);
    ft_strlcpy(res[0],s,s1len);
    ft_strlcpy(res[1],s + s1len,s2len);
    return (res);
}



// char **ft()
// {
//   const char *s = "Hello -World";
//   char c = '-';
//   char **res;
//   char *s1;
//   char *s2;
  
//     size_t s1len;
//     size_t s2len;
//     size_t i;
    
//     i = 0;
//     s1len = 0;
//     s2len = 0;
//     while (s[s1len] && s[s1len] != c)
//         s1len++;
//     s1len++;
//     s2len = strlen(s + s1len) + 1;
//     s1 = malloc(sizeof(char) * s1len);
//     s2 = malloc(sizeof(char) * s2len);
    
//     if(!s1 || !s2)
//         return (0);
//     ft_strlcpy(s1,s,s1len);
//     ft_strlcpy(s2,s + s1len,s2len);
//     res = malloc(sizeof(char*) * 2);
//     res[0] = s1;
//     res[1] = s2;
//     return (res);
// }

/*int main()
{
    char **ar;

    const char *s = "Hello -World";
    ar = ft_split(s, '-');
    printf("%s",ar[0]);
    printf("%s",ar[1]);
}*/
