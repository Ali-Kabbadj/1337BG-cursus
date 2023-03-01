/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:22:28 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 17:29:29 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../printf/ft_printf.h"
# include "formulas.h"
# include "fractmacros.h"
# include "hooks.h"
# include "initializer.h"
# include "sidebar.h"
# include "structs.h"
# include "zoom.h"
# include <math.h>
# include <stdlib.h>

int		exit_program(t_fract *fract);
int		ft_strcmp(const char *s1, const char *s2);
void	default_shared(t_fract *fract);
void	reset_fract(t_fract *fract);

double	coodinates_converter_x(double x, t_fract *fract);
double	coodinates_converter_y(double y, t_fract *fract);

void	ft_move_color(t_fract *fract, int key);
void	set_pixel_color(t_fract *fract);
void	render_fract(t_fract *fract);
void	rerender_fract(t_fract *fract);
void	mlx_put_pixel_img(t_fract *fract);
void	handle_input(int ac, char **cmd_input, t_fract *fract);
void	cal_bouderies(t_fract *fract, double mouse_x, double mouse_y);
void	render(t_fract *fract);
void	iteration(t_fract *fract);
#endif
