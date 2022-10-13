/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:35:34 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 23:08:07 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int slen;

	slen = 0;
	if (s == NULL)
		return (0);
	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (s[slen] == c)
			return ((char *)s + slen);
		slen--;
	}
	return (0);
}

/*int main()
{
	char *str = NULL;
	// char *ptr = strrchr(str, 'a');
	char *ptr1 = ft_strrchr(str, 'a');
	// printf("dyalna%s\n", ptr);
	printf("dyalna%s", ptr1);
	return 0;
}*/
