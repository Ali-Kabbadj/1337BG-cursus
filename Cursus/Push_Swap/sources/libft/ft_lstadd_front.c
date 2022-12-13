/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:33:45 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:38:24 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
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

	ft_lstadd_front(list, nodeone);
	ft_lstadd_front(list, nodetwo);
	ft_lstadd_front(list, nodethree);
	
	int i;
	i = 0;
	
	t_list *tmp;
	tmp = (*list);
	
	while(tmp)
	{
		printf("%d | %s\n",i, (char *)(tmp->content));
		tmp = tmp->next;
		i++;
	}
}*/
