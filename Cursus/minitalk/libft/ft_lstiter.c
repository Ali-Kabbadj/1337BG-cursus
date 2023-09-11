/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:14:11 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 22:42:13 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*templ;

	if (lst && f)
	{
		templ = lst;
		while (templ)
		{
			(*f)(templ->content);
			templ = templ->next;
		}
	}
}
/*void f(void *content)
{
	int i;

	i = 0;
	while(((char*)content + i))
	{
		if (((char)content + i) >= 'a' && ((char*)content + i))
			((char)content + i) = (((char)content + i) - 32);
		i++;
	}
}
#include <stdio.h>
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

	ft_lstiter(*list,f);

	t_list *tmp;
	tmp = (*list);
	while(tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}*/
