/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:49:05 by akabbadj          #+#    #+#             */
/*   Updated: 2022/11/02 23:35:13 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*previous;

	if (lst && *lst && del)
	{
		previous = *lst;
		while (previous)
		{
			next = previous->next;
			ft_lstdelone(previous, del);
			previous = next;
		}
		*lst = NULL;
	}
}
