/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:12:30 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 02:58:09 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dst, const void *src , size_t n)
{
	int		i;
	char *dst1;
	char *src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	i = 0;
	while(dst1[i])
	{
		dst1[i] = src1[i];
		i++;
	}
	dst1[i] = '\0';
	return (dst1);
}
