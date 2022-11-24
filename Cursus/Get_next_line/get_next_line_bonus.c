/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:30 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/23 00:38:34 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <limits.h>

char	*get_next_line(int fd)
{
	static char		*store[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (store[fd])
		{
			free(store[fd]);
			store[fd] = 0;
		}
		return (0);
	}
	if (store[fd] && has_linebreak(store[fd]))
	{
		line = extract_line(store[fd]);
		store[fd] = extract_rest(store[fd]);
		return (line);
	}
	store[fd] = read_and_store(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = extract_line(store[fd]);
	store[fd] = extract_rest(store[fd]);
	return (line);
}

char	*extract_rest(char *store)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	if (store[i] == '\n')
		i++;
	res = malloc(sizeof(char) * i + 1);
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
	if (!buff)
		return (0);
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

// #include <fcntl.h>
// #include <sys/stat.h>
// void ft_putstr_fd(char *s, int fd)
// {
// 	int i;
// 	i = 0;
// 	while(s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }

// int main(void)
// {
//     int fd = open("hello.txt" ,O_RDWR|O_CREAT , S_IWUSR | S_IRUSR);
// 	if (read(fd, 0, 1) == 0)
// 	{
//     	ft_putstr_fd("abcdefgh\nijklmnop\n\nqrstuv\nurst\n.", fd);
// 		close(fd);
// 	}
// 	fd = open("hello.txt" ,O_RDWR|O_CREAT , S_IWUSR | S_IRUSR);
// 	printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
