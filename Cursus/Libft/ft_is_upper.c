/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:33:34 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 00:03:00 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_upper(int c)
{
	if(c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	return (0);
}
