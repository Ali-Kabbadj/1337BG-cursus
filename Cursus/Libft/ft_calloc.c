/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:43:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/02 06:30:26 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	buffer = malloc(count * size);
	if (!buffer)
		return (0);
	ft_bzero(buffer, count * size);
	return (buffer);
}
/*#include <limits.h>
#include <stdio.h>
int main()
{
	void *s;
	s = malloc(18446744073709551615);
	printf("\n%lu", SIZE_MAX);
}/*
