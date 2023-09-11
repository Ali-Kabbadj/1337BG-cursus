/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:55:18 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:05:52 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*#include <stdio.h>
int main()
{
	char c;
	scanf("%c", &c);
	if (ft_isalnum(c))
		printf("%c is a an alnum",c);
	else
		printf("%c is not an alnum", c);
}*/
