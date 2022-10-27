/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:38:53 by akabbadj          #+#    #+#             */
/*   Updated: 2022/10/27 13:57:34 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list *templ;
	int count;

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
