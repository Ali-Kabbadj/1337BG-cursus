/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:52:04 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/03 23:19:30 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*#include <stdio.h>
int main()
{
	char c;
	printf("Enter a value :");
	scanf("%c", &c);
	if (ft_isdigit(c))
		printf("%c is a digit.",c);
	else
		printf("%c is not a digit.",c);
	return (0);
}*/
