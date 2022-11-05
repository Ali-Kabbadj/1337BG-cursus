/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:35:40 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 23:13:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char b[] = "abcdefgh";
	int c;
	int len;
	char *res;

	c = 'a';
	len = 0;

	printf("mine : %s\n", ft_memset((void *)b, c, len));
	printf("original : %s", memset((void *)b, c, len));
}*/
