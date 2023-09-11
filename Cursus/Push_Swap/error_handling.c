/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:59:57 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/10 23:59:45 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	exit_program(char *error_mssg, int error_id)
{
	ft_printf("error %d : %s", error_id, error_mssg);
	exit(error_id);
}
