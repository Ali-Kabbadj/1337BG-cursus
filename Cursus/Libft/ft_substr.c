/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:58:22 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/31 20:42:19 by alika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*emptyarray(void)
{
	char	*s;

	s = malloc(sizeof(char) * 1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(s);
	if (start > slen || !len)
		return (emptyarray());
	if (len >= slen)
		len = slen - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*int main()
{
	char *str = ft_strdup("0123456789");
	char *s = ft_substr(str, 9, 10);

	printf("%s",s);
}*/
