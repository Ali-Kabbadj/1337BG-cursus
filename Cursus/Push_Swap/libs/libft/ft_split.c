/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 06:02:09 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/11 01:00:42 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_word_count(const char *str, char wordsep)
{
	int	i;
	int	wordcount;
	int	counted;

	i = 0;
	wordcount = 0;
	counted = 0;
	while (str[i])
	{
		if (str[i] != wordsep && counted == 0)
		{
			wordcount++;
			counted = 1;
		}
		else if (str[i] == wordsep)
			counted = 0;
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
	if (!word)
		return (0);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_clear(char **split)
{
	size_t	i;

	i = 0;
	while (*(split + i))
	{
		free(*split + i);
		i++;
	}
	free(split);
}

static int	spliter(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_create_word(s, index, i);
			if (!split[j])
				return (j);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;

	j = 0;
	if (!s)
		return (0);
	split = malloc((ft_get_word_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	j = spliter(split, s, c);
	if (j != -1 || j == 0)
	{
		ft_clear(split);
		split = NULL;
	}
	return (split);
}
