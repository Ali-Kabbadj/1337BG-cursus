/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:43:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 23:15:52 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (size && count > SIZE_MAX / size)
		return (0);
	buffer = malloc(count * size);
	if (!buffer)
		return (0);
	ft_bzero(buffer, count * size);
	return (buffer);
}
/*#include <stdio.h>
int main()
{
	size_t a = SIZE_MAX;
	printf("%p\n" , calloc(a -(a / 2), 1));
	//printf("%p", ft_calloc(a , 1));
}*/
