/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:44:38 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/08 09:02:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;

	s1len = 0;
	s2len = 0;
	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2) + 1;
	res = malloc((s1len + s2len) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, (const void *)s1, s1len);
	ft_memcpy(res + s1len, (const void *)s2, s2len);
	return (res);
}
/*#include <stdio.h>
int main()
{
	char const *s1 = "abcde";
	char const *s2 = "ghijk";

	char *res = ft_strjoin(s1, s2);
	printf("%s", res);

}*/
