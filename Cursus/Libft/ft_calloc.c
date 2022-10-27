/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:43:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/27 22:47:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (!count || !size || size == SIZE_MAX || count == SIZE_MAX)
		return (0);
	buffer = malloc(count * size);
	if (!buffer)
		return (0);
	ft_bzero(buffer, count * size);
	return (buffer);
}
