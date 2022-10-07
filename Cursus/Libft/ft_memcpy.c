/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:12:30 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/06 23:37:54 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *restrict dst, const void *restrict src , size_t n)
{
	int		i;
	void	*newdst;

	i = 0;
	newdst = malloc(sizeof(dst));

	while(dst[i])
	{
		newdest[i] = dst[i];
		i++;
	}
	newdst[i] = '\0';

	i = 0;
	while(i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (newdst);
}
