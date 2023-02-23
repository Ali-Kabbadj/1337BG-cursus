/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:26:12 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/23 09:27:59 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	controlle_iteration_nb(t_fract *fract, int keycode)
{
	if (keycode == K_I_CHAR)
		fract->vars.iterations += 10;
	else if (keycode == K_O_CHAR)
		fract->vars.iterations -= 10;
}

void	move_fract(t_fract *fract, int keycode)
{
	if (keycode == K_UP_ARROW)
		fract->vars.move_y += fract->vars.move;
	else if (keycode == K_DOWN_ARROW)
		fract->vars.move_y -= fract->vars.move;
	else if (keycode == K_LEFT_ARROW)
		fract->vars.move_x += fract->vars.move;
	else if (keycode == K_RIGTH_ARROW)
		fract->vars.move_x -= fract->vars.move;
}

void	pause_upause(t_fract *fract)
{
	if (fract->vars.pause_julia == 1)
		fract->vars.pause_julia = 0;
	else
		fract->vars.pause_julia = 1;
}
