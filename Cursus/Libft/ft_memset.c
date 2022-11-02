/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:35:40 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/02 07:18:23 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)(b + i)) = (unsigned char)c;
		i++;
	}
	return (b);
}
