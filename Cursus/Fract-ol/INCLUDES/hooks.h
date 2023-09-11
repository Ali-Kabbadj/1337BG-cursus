/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:59:52 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 13:31:30 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "structs.h"

int		handle_keypress(int keycode, t_fract *fract);
int		handle_mouse_input(int button, int x, int y, t_fract *fract);
int		loop_hook(t_fract *fract);
void	controlle_iteration_nb(t_fract *fract, int keycode);
void	move_fract(t_fract *fract, int keycode);
void	pause_upause(t_fract *fract, int keycode);
void	mouse_pointer_availability(t_fract *fract);
void	switch_fract(t_fract *fract, int keycode);
#endif