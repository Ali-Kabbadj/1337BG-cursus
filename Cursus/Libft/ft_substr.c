/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:58:22 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/22 10:58:28 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

	slen = 0;
	res = NULL;
	if (!len)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (start >= slen)
		return (0);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_memset(res, '\0', len + 1);
	ft_memmove(res, (const char *)s + start, len);
	return (res);
}

// int main()
// {
//     char *s = "Hello-The substring";
//     printf("%s",ft_substr(s,6,13));
// }
