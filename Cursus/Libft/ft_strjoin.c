/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:44:38 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/01 22:56:25 by akabbadj         ###   ########.fr       */
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
	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2) + 1;
	res = malloc((s1len + s2len) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, (const void *)s1, s1len);
	ft_memcpy(res + s1len, (const void *)s2, s2len);
	return (res);
}
