/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:46 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:47:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	if (lst)
	{
		lastnode = lst;
		while (lastnode->next)
			lastnode = lastnode->next;
		return (lastnode);
	}
	return (0);
}
/*#include <stdio.h>
int main()
{
	char *s1 = "three";
	char *s2 = "two";
	char *s3 = "one";

	t_list **list;
	list = malloc(sizeof(t_list) * 4);
	(*list) = NULL;

	t_list *nodeone;
	nodeone = ft_lstnew(s1);

	t_list *nodetwo;
	nodetwo = ft_lstnew(s2);

	t_list *nodethree;
	nodethree = ft_lstnew(s3);

	ft_lstadd_front(list, nodeone);
	ft_lstadd_front(list, nodetwo);
	ft_lstadd_front(list, nodethree);

	t_list *lastnode = ft_lstlast(*list);

	printf("%s\n", (char *)lastnode->content);
}*/
