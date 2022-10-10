/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:38:51 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 21:25:38 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	if(dst == src)
		return (dst);
	if(dst < src)
	{
		while(i < len)
		{
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
			i++;
		}
	}
	else
	{
		while(len > 0)
		{
			*((unsigned char*)dst + len - 1) = *((unsigned char*)src  +len - 1);
			len--;
		}
	}
	return (dst);
}
