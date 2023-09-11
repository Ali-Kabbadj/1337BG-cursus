/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:28:30 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/01 17:29:13 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULAS_H
# define FORMULAS_H
# include "structs.h"

void	mandelbrot_julia_formula(t_complexe *z, t_complexe c);
void	burning_ship_julia_formula(t_complexe *z, t_complexe c);
void	burning_ship_formula(t_complexe *z, t_complexe c);
void	custom_julia_formula(t_complexe *z, t_complexe c);
double	absolute_value(t_complexe z);
#endif
