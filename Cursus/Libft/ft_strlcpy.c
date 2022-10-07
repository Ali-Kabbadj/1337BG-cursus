/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:45:43 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/07 00:00:40 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	strlcpy(char *dst, const char *src, size_t size)
{
	int	srclen;

	srclen = ft_strlen(src);
	if (size <= 0)
		return srclen;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);	
}
