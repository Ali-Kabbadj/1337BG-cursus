/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:59:54 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:06:11 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*#include <stdio.h>
int main()
{
	char c;
	printf("Enter a value : ");
	scanf("%c", &c);
	if (ft_isascii(c))
		printf("%c is an ascii value", c);
	else
		printf("%c is not an ascii value", c);
}*/
