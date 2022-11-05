/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:52:39 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 04:17:01 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && (*del))
	{
		(*del)(lst->content);
		free(lst);
	}
}
/*void del(void *content)
{
	free(content);
}
#include <stdio.h>
int main()
{
	const char *s1 = "one";
	const char *s2 = "two";
	const char *s3 = "three";

	t_list **list;
	list = malloc(sizeof(t_list) * 4);
	(*list) = NULL;

	t_list *nodeone;
	nodeone = ft_lstnew(ft_strdup(s1));

	t_list *nodetwo;
	nodetwo = ft_lstnew(ft_strdup(s2));

	t_list *nodethree;
	nodethree = ft_lstnew(ft_strdup(s3));

	ft_lstadd_front(list, nodethree);
	ft_lstadd_front(list, nodetwo);
	ft_lstadd_front(list, nodeone);

	int i;
	i = 0;

	ft_lstdelone(nodethree , del);

	t_list *tmp;
	tmp = (*list);

	while(tmp)
	{
		printf("%d | %s\n",i, (char *)(tmp->content));
		tmp = tmp->next;
		i++;
	}
}*/
