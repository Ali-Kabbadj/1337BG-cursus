/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:03:19 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/18 11:57:48 by alika            ###   ########.fr       */
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
