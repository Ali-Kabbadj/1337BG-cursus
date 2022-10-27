/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:57:46 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/27 14:04:03 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{	
	if (lst)
	{
		t_list *lastnode;
	
		lastnode = lst;
		while (lastnode->next)
			lastnode = lastnode->next; 
		return (lastnode);
	}
	return (0);
}
