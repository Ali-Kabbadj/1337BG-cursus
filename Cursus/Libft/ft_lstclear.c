/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:49:05 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/30 17:13:40 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst && del)
	{
		while (*lst)
		{
			(*del)((*lst)->content);
			free(*lst);
			*lst = (*lst)->next;
		}
		lst = NULL;
	}
}
