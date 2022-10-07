/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 03:58:42 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/07 04:08:52 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
int		ft_toupper(int c, locale_t loc);
int		ft_tolower(int c, locale_t loc);
char	*ft_strrchr(const char *s, int c);
char	*strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
size_t	strcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char 	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, int len);
void 	*ft_memove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		memcmp(const void *s1, const void *s2, size_t n);
void	*memchr(const void *s, int c, size_t n);
int		ft_isprint(int c);
int 	ft_isdigit(int c);
int		ft_isascii(int c);
int		isalpha(int c);
int		ft_isalnum(int c);
int		ft_is_upper(int c);
int		ft_is_lower(int c);
void	ft_bzero(void *s, size_t n);
int		atoi(const char *str);
#endif
