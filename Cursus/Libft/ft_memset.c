/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:35:40 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/09 22:19:01 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memset(void *b, int c , int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		*((unsigned char*)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

/*int main ()
{
	char src[10] = "abcdefgh";
	ft_memset(src, 'x', 4);
	printf("%s",src);

	int i;
    i = 0;
	int array[10] = {5 , 5 , 5 ,5};
	memset(array, 1, sizeof(int) * 4);
	while(i < 4)
	    printf("%d\n",array[i++]);
}*/
