/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:30 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/18 19:32:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*store;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (store)
		{
			free(store);
			store = 0;
		}
		return (0);
	}
	store = read_and_store(fd, store);
	if (!store)
		return (NULL);
	line = extract_line(store);
	store = extract_rest(store);
	return (line);
}

char	*extract_rest(char *store)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!store)
		return (0);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\0')
	{
		free(store);
		return (0);
	}
	if (store[i] == '\n')
		i++;
	res = malloc(ft_strlen(store) - i + 1);
	if (!res)
		return (0);
	while (store[i])
		res[j++] = store[i++];
	res[j] = '\0';
	free(store);
	return (res);
}

char	*extract_line(char *store)
{
	char	*res;
	int		i;

	i = 0;
	if (!store[i])
		return (0);
	while (store[i] && store[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (0);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		res[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

int	has_linebreak(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_and_store(int fd, char *stored)
{
	int		readcount;
	char	*buff;

	readcount = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!has_linebreak(stored) && readcount > 0)
	{
		readcount = read(fd, buff, BUFFER_SIZE);
		if (readcount == -1)
		{
			free(buff);
			return (0);
		}
		buff[readcount] = '\0';
		stored = ft_strjoin(stored, buff);
	}
	free(buff);
	return (stored);
}
// int main(void)
// {
//     int fd = open("hello.txt",O_CREAT | O_RDONLY);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//    printf("%s", get_next_line(fd));
// //     printf("%s", get_next_line(fd));
//         // get_next_line(fd);
//         // get_next_line(fd);
//         // get_next_line(fd); 
//     return (0);
// }
