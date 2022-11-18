/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:39 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/17 21:27:40 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <sys/types.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 5
#endif

char *ft_strjoin(char *s1, const char *s2);
char *get_next_line(int fd);
int has_linebreak(char *s);
char *read_and_store(int fd, char *stored);
char *extract_line(char *line);
size_t ft_strlen(const char *s);
char *extract_rest(char *line);
char *extract_line(char *line);
#endif

