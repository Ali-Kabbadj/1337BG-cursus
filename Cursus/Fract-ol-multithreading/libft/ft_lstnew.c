/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:24:04 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:16:05 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}
/*#include <stdio.h>
int main()
{
	char *s = "new node";
	t_list *res;
	res = ft_lstnew(s);
	printf("%s",(char *)res->content);
	printf("%s",(char *)res->next);
}*/
