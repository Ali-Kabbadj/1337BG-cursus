/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:43:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/09 22:15:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *calloc(size_t count, size_t size)
{
	void *buffer;
	if(!(buffer = malloc(count * size)))
		return (0);
	return (buffer);
}
