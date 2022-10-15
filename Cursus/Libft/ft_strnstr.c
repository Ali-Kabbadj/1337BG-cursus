/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:03:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/15 06:22:17 by alika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (haystack == needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i] && needle[j] && i < len)
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

// int main()
// {
// 	char *str = "hello";
// 	char *ptr = ft_strnstr(str, (void*)0, 0);
// 	//char *ptr1 = strnstr(str, (void*)0, 0);
// 	printf("dyalna : %s\n", ptr);
// 	//printf("dyalhoum :%s", ptr1);
// 	return 0;
// }
