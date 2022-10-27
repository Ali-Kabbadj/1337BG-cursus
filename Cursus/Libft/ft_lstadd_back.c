/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:37 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/27 21:47:38 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list  **lst, t_list *new)
{
	t_list	*lastnode;

	if (lst == NULL)
		(*lst)->next = ft_lstnew(new->content);
	else if (new == NULL)
		(*lst)
	else
	{
		lastnode = malloc(sizeof(t_list));
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
	}
}
