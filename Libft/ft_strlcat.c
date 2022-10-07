/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:57:57 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/07 00:13:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	int lentocpy;
	
	i = 0;
	j = 0;
	lentocpy = size - ft_strlen(dst);
	while(dst[i])
		i++;
	while(src[j] && j < lentocpy)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ();
}
