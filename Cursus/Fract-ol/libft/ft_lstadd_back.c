/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:37 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:54:00 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (*lst && new)
	{	
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
	}
	else
	{
		*lst = new;
	}
}
/*#include <stdio.h>
int main()
{
	char *s1 = "one";
	char *s2 = "two";
	char *s3 = "three";

	t_list **list;
	list = malloc(sizeof(t_list) * 4);
	(*list) = NULL;

	t_list *nodeone;
	nodeone = ft_lstnew(s1);

	t_list *nodetwo;
	nodetwo = ft_lstnew(s2);

	t_list *nodethree;
	nodethree = ft_lstnew(s3);

	ft_lstadd_front(list, nodethree);
	ft_lstadd_front(list, nodetwo);
	ft_lstadd_front(list, nodeone);

	t_list *addbacknode;
	char *s4 = "last";
	addbacknode = ft_lstnew(s4);

	ft_lstadd_back(list, addbacknode);

	t_list *tmp;
	tmp = (*list);
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}*/
