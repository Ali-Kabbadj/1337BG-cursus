/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:59:18 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 23:19:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while(i < n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	return (*((unsigned char*)s1 + i) - ((unsigned char)s2 + i));
}
