/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:57:57 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 04:19:48 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	int dstlen;
	int srclen;
	int lentocpy;
	
	i = 0;
	j = 0;
	while(dst[i])
		i++;
	dstlen = i;
	lentocpy = dstsize - dstlen - 1;
	while(src[j] && j < lentocpy)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	srclen = j;
	if(dstlen + srclen);

	dst[i] = '\0';
	return ();
}
