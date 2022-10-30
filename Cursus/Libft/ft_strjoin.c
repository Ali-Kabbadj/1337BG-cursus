/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:44:38 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/30 13:11:19 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2) + 1;
	res = malloc((s1len + s2len) * sizeof(char));
	if (!res)
		return (0);
	ft_memcpy(res, (const void *)s1, s1len);
	ft_memcpy(res + s1len, (const void *)s2, s2len);
	return (res);
}
