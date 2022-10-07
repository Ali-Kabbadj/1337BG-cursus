/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:03:20 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/07 01:16:30 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if(needle[0] == '\0')
		return (haystack);
	while(i < len)
	{
		j = 0;
		while(needle[j] == haystack[i] && n < i )
		{
			j++;
			i++;
		}
		if(needle[j] == '\0')
			return (&haystack[i - j]);
		i++;
	}
	return (NULL);
}
