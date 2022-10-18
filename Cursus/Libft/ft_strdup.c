/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:42:23 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/18 11:17:20 by alika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		slen;

	slen = ft_strlen(s1) + 1;
	res = (char *)malloc(slen * sizeof(char));
	if (!res)
		return (0);
	ft_bzero(res, slen);
	return ((char *)ft_memmove(res, s1, slen));
}
