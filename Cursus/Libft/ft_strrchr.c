/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:35:34 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 23:08:07 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *strrchr(const char *s, int c)
{
	int slen;

	slen = ft_strlen(s);
	if(c == '\0')
		return ((char *)s + slen);
	while(slen >= 0)
	{
		if(s[slen] == c)
			return ((char *)s + slen);
		slen--;
	}
	return (0);
}
