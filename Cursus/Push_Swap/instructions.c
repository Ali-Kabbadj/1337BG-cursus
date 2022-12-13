/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:11:59 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/13 00:12:02 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_digit(int d)
{
	if (d == 15)
		return (0);
	return (1);
}

void	sa(int *a)
{
	int	tmp;

	if (is_digit(a[0]) || is_digit(a[1]))
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		printf("sa\n");
	}
}

void	sb(int *b)
{
	int	tmp;

	if (is_digit(b[0]) || is_digit(b[1]))
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
}

void	ss(int *a, int *b)
{
	sa(a);
	sb(b);
}

void	pa(int *a, int *b)
{
	int	i;

	i = 0;
	if (is_digit(b[0]))
    {
        while (is_digit(a[i]))
            i++;
        a[i + 1] = 15;
        while(i > 0)
        {
          a[i] = a[i - 1];
          i--;
        }
        a[0] = b[0];
        i = 0;
        while (b[i] != 15)
        {
          b[i] = b[i + 1];
          i++;
        }
    }
}

void	pb(int *a, int *b)
{
	pa(b, a);
}

void	ra(int *a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a[0];
	while (is_digit(a[i]))
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = tmp;
	printf("ra\n");
}

void	rb(int *b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = b[0];
	while (is_digit(b[i]))
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = tmp;
}

void    rr(int *a, int *b)
{
    ra(a);
    rb(b);
}

void	rra(int *a)
{
	int	i;
	int	tmp;

	i = 0;
     while (is_digit(a[i]))
      i++;
    i--;
    tmp = a[i];
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[i] = tmp;
	printf("rra\n");
}

void	rrb(int *b)
{
	int	i;
	int	tmp;

	i = 0;
     while (is_digit(b[i]))
      i++;
    i--;
    tmp = b[i];
    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }
    b[i] = tmp;
}

void    rrr(int *a, int *b)
{
    rra(a);
    rrb(b);
}
