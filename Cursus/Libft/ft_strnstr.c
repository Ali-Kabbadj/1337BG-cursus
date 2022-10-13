/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:03:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/08 23:21:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!needle || len == 0)
		return ((char *)haystack);
	while (i < len)
	{
		j = 0;
		while (needle[j] == haystack[i])
		{
			j++;
			i++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i - j);
		i++;
	}
	return (0);
}

/*int main()
{
	char *str = "hello";
	char *ptr = ft_strnstr(str, "l", 3);
	char *ptr1 = strnstr(str, "l", 3);
	printf("dyalna : %s\n", ptr);
	printf("dyalhoum :%s", ptr1);
	return 0;
}*/
