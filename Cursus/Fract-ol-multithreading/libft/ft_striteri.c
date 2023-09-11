/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikabbadj <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:47:59 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 23:36:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
/*#include <stdio.h>
void f(unsigned int i, char * s)
{
	s[0] = 'b';
}
int main()
{
	char s[5] = "aaaa";
	ft_striteri(s,f);
	printf("%s",s);
}*/
