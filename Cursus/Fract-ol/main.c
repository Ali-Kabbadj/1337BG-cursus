/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:38:26 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/22 23:38:07 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// int julia_params(double re, double img)
// {
	
// }

// static double ft_atof(char *f)
// {
// 	char *real_s;
// 	char *decimal_s;
// 	int real;
// 	int decimal;
// 	int sep_idx;
// 	int i;
// 	int sign;

// 	double res;

// 	res = 0;
// 	i = 0;
// 	sign = 1;
// 	sep_idx = 0;
// 	real = 0;
// 	decimal = 0;
// 	if (f[0] == '-')
// 		sign = -1;
// 	while (f[sep_idx] && f[sep_idx] != '.' && f[sep_idx] != ',')
// 		sep_idx++;
// 	if (f[sep_idx] != '.' && f[sep_idx] != ',')
// 		return (-999);
// 	real_s = malloc(sizeof(char) * sep_idx);
// 	while (f[i] != '.' && f[i] != ',')
// 	{
// 		real_s[i] = f[i];
// 		i++;
// 	}
// 	real_s[i] = '\0';
// 	sep_idx++;
// 	i = 0;
// 	while (f[sep_idx + i] && ft_isdigit(f[sep_idx + i]))
// 		i++;
// 	decimal_s = malloc(sizeof(char) * i);
// 	i = 0;
// 	while (f[sep_idx + i] && ft_isdigit(f[sep_idx + i]) )
// 	{
// 		decimal_s[i] = f[sep_idx + i];
// 		i++;
// 	}
// 	decimal_s[i] = '\0';
// 	real = ft_atoi(real_s);
// 	decimal = ft_atoi(decimal_s);
// 	res = decimal;
// 	while (i > 0)
// 	{
// 		res = res / 10 + ((decimal % 10) / 10);
// 		decimal = decimal / 10 ;
// 		i--;
// 	}
// 	return(res * sign);
// }

int	main(int ac, char **av)
{
	t_fract	*fract;

	// if (ac < 2 || (ft_strcmp(av[1], "julia") && ft_strcmp(av[1],
	// 			"mandelbrot")))
	// {
	// 	ft_printf("Syntax : ./fractol <julia> or <mandelbrot>");
	// 	return (0);
	// }
	printf("%d",ac);
	fract = malloc(sizeof(t_fract));
	//handle_input(ac, av, fract);
	if (!fract)
		return (0);
	init_fract_type(fract, av[1]);
	init_mlx_vars(fract);
	init_img(fract);
	init_vars(fract);
	// if (!ft_strcmp(av[1], "julia") && ac >= 4)
	// {
	// 	fract->vars.c.real = ft_atof(av[2]);
	// 	fract->vars.c.imag = ft_atof(av[3]);
	// }
	render_fract(fract);
	init_hooks(fract);
	mlx_loop(fract->mlx_vars.mlx_ptr);
	return (0);
}
