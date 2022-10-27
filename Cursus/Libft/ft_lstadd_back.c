/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:37 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/27 15:51:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list  **lst, t_list *new)
{
	t_list	*lastnode;

	lastnode = malloc(sizeof(t_list));
	if (lst && new)
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
	}
}
