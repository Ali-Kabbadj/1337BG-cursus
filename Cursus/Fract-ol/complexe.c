/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:21:48 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/15 18:12:43 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double add_real(t_complexe *z1, t_complexe *z2)
{
    return (z1->z_real + z2->z_real);
}

double add_imag(t_complexe *z1, t_complexe *z2)
{
    return (z1->z_imag + z2->z_imag);
}

double multiply_real(t_complexe *z1, t_complexe *z2)
{
    return(z1->z_real * z2->z_real - z1->z_imag * z2->z_imag);
}

double multiply_imag(t_complexe *z1, t_complexe *z2)
{
    return(z1->z_real * z2->z_imag + z2->z_real * z1->z_imag);
}

double squared_modulus(t_complexe *z)
{
    return(sqrt(z->z_real * z->z_real + z->z_imag * z->z_imag)); 
}