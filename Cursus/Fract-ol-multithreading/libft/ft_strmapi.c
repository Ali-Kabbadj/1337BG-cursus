/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:26:58 by alika             #+#    #+#             */
/*   Updated: 2022/11/04 23:41:45 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	i = 0;
	if (!s || (!s && !f))
		return (0);
	else if (!f)
		return (ft_strdup(s));
	rtn = ft_strdup(s);
	if (!rtn)
		return (0);
	while (s[i])
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	return (rtn);
}
/*#include <stdio.h>
char f(unsigned int i, char c)
{
	c = 'b';
	i = 0;
	return ('b');
}
int main()
{
	char s[5] = "aaaa";
	char *res = ft_strmapi(s, f);
	printf("%s",res);
}*/
