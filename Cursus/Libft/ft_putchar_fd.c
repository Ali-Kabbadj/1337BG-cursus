/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alika <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:59:14 by akabadj           #+#    #+#             */
/*   Updated: 2022/11/03 01:44:07 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
int main()
{
	int fd1 = open("filetest.txt", O_CREAT | O_RDWR);
	printf("%d\n\n",fd1);
	if (fd1 != -1)
		ft_putstr_fd("this is an array",fd1);
	else
		printf("something went wrong");
	
}
*/
