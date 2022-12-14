/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:42:23 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 01:28:21 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	res = malloc(slen * sizeof(char));
	if (!res)
		return (0);
	ft_bzero(res, slen);
	return ((char *)ft_memmove(res, s1, slen));
}
