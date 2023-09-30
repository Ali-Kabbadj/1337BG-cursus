/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:38:53 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/04 03:46:41 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list		*templ;
	int			count;

	count = 0;
	if (!lst)
		return (count);
	templ = lst;
	while (templ->next)
	{
		templ = templ->next;
		count++;
	}
	count++;
	return (count);
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

	printf("%d", ft_lstsize(*list));
}*/
