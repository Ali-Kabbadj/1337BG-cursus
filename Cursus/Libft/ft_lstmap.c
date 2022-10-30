/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:31:46 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/30 17:58:59 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del(void *)))
{
	t_list	*resl;
	t_list	*tmpl;
	t_list	*restmp; 

	resl = malloc(sizeof(t_list));
	if (!resl)
		return (0);
	tmpl = lst;

	res = ft_lstnew((*f)(tmpl->content));
	restmp = res;

	restmp = restmp->next;
	tmpl = tmpl->next;
	while (tmpl)
	{
		restmp = ft_lstnew((*f)(tmpl->content));
		restmp = restmp->next;
		tmpl = tmpl->next;
	}
	return (resl);
}
