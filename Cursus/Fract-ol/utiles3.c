/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:00:29 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/02 13:25:56 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/fractol.h"

void	put_int_to_win(t_fract *fract, int x, int y, int nb)
{
	char	*str_nb;

	str_nb = ft_itoa(nb);
	mlx_string_put(fract->mlx_vars.mlx_ptr, fract->mlx_vars.win_ptr, x, y,
		BLACK, str_nb);
	free(str_nb);
}
