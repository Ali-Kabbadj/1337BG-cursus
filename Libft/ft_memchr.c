/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:48:50 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/07 00:58:51 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while(s[i] && i < n)
	{
		if(s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if(c == '\0' && i < n)
		return (&s[i]);
	return (NULL);
}
