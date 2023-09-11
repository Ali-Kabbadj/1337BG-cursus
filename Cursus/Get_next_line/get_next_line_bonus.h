/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:39 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/23 00:38:43 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char			*ft_strjoin(char *s1, const char *s2);
char			*get_next_line(int fd);
int				has_linebreak(char *s);
char			*read_and_store(int fd, char *stored);
char			*extract_line(char *line);
unsigned int	ft_strlen(const char *s);
char			*extract_rest(char *store);
char			*ft_strdup(const char *s1);
char			*extract_line(char *store);

#endif
