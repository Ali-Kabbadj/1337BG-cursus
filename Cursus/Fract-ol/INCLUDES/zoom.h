/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:20:03 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 17:30:38 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_H
# define ZOOM_H
# include "structs.h"

void	cal_local_zoom(t_fract *fract, double mouse_x, double mouse_y);
void	cal_centered_zoom(t_fract *fract);
void	handle_mouse_zoom(t_fract *fract, int x, int y, int button);
void	handle_keyboard_zoom(t_fract *fract, int keycode);
#endif