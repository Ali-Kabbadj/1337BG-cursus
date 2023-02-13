/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:04:05 by akabbadj          #+#    #+#             */
/*   Updated: 2023/02/13 01:34:17 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
		if (!*s1++ || !*s2++)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	bzero_tab(unsigned int *tab)
{
	int	i;

	i = 0;
	while (i < WIDTH * WIDTH)
	{
		tab[i] = 0;
		i++;
	}
}

void	color_split(t_mlx_var *id, t_fract_vars *var, t_input *inp, int i)
{
	if (i % 16 == 7)
		id->tab[var->y * WIDTH + var->x] = 3767761;
	else if (i % 16 == 8)
		id->tab[var->y * WIDTH + var->x] = 8828389;
	else if (i % 16 == 9)
		id->tab[var->y * WIDTH + var->x] = 13888760;
	else if (i % 16 == 10)
		id->tab[var->y * WIDTH + var->x] = 15854015;
	else if (i % 16 == 11)
		id->tab[var->y * WIDTH + var->x] = 16304479;
	else if (i % 16 == 12)
		id->tab[var->y * WIDTH + var->x] = 16755200;
	else if (i % 16 == 13)
		id->tab[var->y * WIDTH + var->x] = 13402112;
	else if (i % 16 == 14)
		id->tab[var->y * WIDTH + var->x] = 10049280;
	else if (i % 16 == 15)
		id->tab[var->y * WIDTH + var->x] = 6960131;
}

void	color(t_mlx_var *id, t_fract_vars *var, t_input *inp, int i)
{
	if (i == inp->iteration_max)
		id->tab[var->y * WIDTH + var->x] = 0;
	else if (i % 16 == 0)
		id->tab[var->y * WIDTH + var->x] = 4333071;
	else if (i % 16 == 1)
		id->tab[var->y * WIDTH + var->x] = 1640218;
	else if (i % 16 == 2)
		id->tab[var->y * WIDTH + var->x] = 590127;
	else if (i % 16 == 3)
		id->tab[var->y * WIDTH + var->x] = 263241;
	else if (i % 16 == 4)
		id->tab[var->y * WIDTH + var->x] = 1892;
	else if (i % 16 == 5)
		id->tab[var->y * WIDTH + var->x] = 797834;
	else if (i % 16 == 6)
		id->tab[var->y * WIDTH + var->x] = 1594033;
	else
		color_split(id, var, inp, i);
}

void	color_input(int key, t_input *inp)
{
	if (key == 18)
		inp->color_id = 1;
	else
		inp->color_id = 2;
	if (key == 19)
		inp->color_value = 9999;
	if (key == 20)
		inp->color_value = 333333;
	if (key == 21)
		inp->color_value = 555555;
}


static	int		ft_len_str(int nb)
{
	int len;

	len = (nb <= 0) ? 1 : 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	return (n < 0 ? (-n) : n);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = (n < 0) ? -1 : 1;
	len = ft_len_str(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}