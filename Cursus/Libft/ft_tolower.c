/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:26:06 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/07 00:27:42 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c, locate_t loc)
{
	if(c >= 'A' && c <= 'Z')
		c = c - 32;
	return (c);
}
