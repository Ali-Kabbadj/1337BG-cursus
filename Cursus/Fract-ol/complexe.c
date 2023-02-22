/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:21:48 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/22 01:15:17 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double add_real(t_complexe *z1, t_complexe *z2)
{
    return (z1->real + z2->real);
}

long double add_imag(t_complexe *z1, t_complexe *z2)
{
    return (z1->imag + z2->imag);
}

// t_complexe add_complexe(t_complexe *z1, t_complexe *z2)
// {
//     t_complexe z;
    
//     z.real = add_real(z1, z2);
//     z.imag = add_imag(z1, z2);
//     return(z);
// }

long double multiply_real(t_complexe z1, t_complexe z2)
{
    return(z1.real * z2.real - z1.imag * z2.imag);
}

long double multiply_imag(t_complexe z1, t_complexe z2)
{
    return(z1.real * z2.imag + z2.real * z1.imag);
}


long double sqrt_root_modulus(t_complexe z)
{
    return(sqrt(z.real * z.real + z.imag * z.imag)); 
}