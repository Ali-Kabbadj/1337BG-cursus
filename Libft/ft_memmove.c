/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:38:51 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/06 23:45:08 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memmove(void *dst, const void *src, size_t len)
{
	int i;
	void *newdst;
	newdst = malloc(sizeof(dst));

	i = 0;

	while(dst[i])
	{
		newdst[i] = dst[i];
		i++;
	}

	while(i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (newdst);
}
