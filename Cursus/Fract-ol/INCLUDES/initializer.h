/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:52:25 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 13:00:46 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H
# include "structs.h"

void	init_fract_name(t_fract *fract);
void	init_fract_type(t_fract *fract, char *name);
void	init_img(t_fract *fract);
void	init_mlx_vars(t_fract *fract);
void	init_vars(t_fract *fract);
void	init_hooks(t_fract *fract);
#endif