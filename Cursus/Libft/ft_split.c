/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 06:02:09 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/30 13:18:30 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_word_count(const char *str, char wordsep)
{
	int	i;
	int	wordcount;
	int	isword;

	i = 0;
	wordcount = 0;
	isword = 0;
	while (str[i])
	{
		if (str[i] != wordsep && isword == 0)
		{
			wordcount++;
			isword = 1;
		}
		else if (str[i] == wordsep)
			isword = 0;
		i++;
	}
	return (wordcount);
}

static char	*ft_create_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((ft_get_word_count(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_create_word(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
