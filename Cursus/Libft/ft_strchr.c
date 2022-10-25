/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:30:03 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/25 03:46:00 by alika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		slen;
	char	*src;

	i = 0;
	src = (char *)s;
	slen = ft_strlen(src);
	if ((char)c == '\0')
		return (src + slen);
	while (src[i])
	{
		if (src[i] == (char)c)
			return (src + i);
		i++;
	}
	return (0);
}
