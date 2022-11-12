/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:33:34 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/22 08:10:28 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c);
	return (0);
}