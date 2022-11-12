/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:39:01 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/03 22:44:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
/*#include <stdio.h>
int main()
{
	char a;
	printf("Enter a value:");
	scanf("%c",&a);
	if (ft_isalpha(a))
		printf("%c is an aphabet",a);
	else
		printf("%c is not an alphabet",a);
}*/
