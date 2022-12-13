/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:37:40 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/12 21:37:43 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_swap(int *a, int *b, int count)
{
	if (count <= 3)
		sort_two_to_three(a, b);
}

void	sort_two_to_three(int *a, int *b)
{
	int	i;

	i = 0;
	if (a[0] > a[1])
	{
		ra(a);
		if (a[0] > a[1])
		{
			sa(a);
		}
		if (a[2] != 15 && a[2] < a[1])
		{
			rra(a);
			sa(a);
		}
	}
	else
	{
		if (a[2] != 15 && a[1] > a[2])
		{
			sa(a);
			ra(a);
			if (a[0] > a[1])
				sa(a);
		}
	}
}

int	main(int argc, char *argv[])
{
	int *a;
	int *b;
	int n;
	n = 0;
	if (argc == 1)
		return (0);
	a = malloc(sizeof(int *) * argc);
	b = malloc(sizeof(int *) * argc);
	for (int i = 1; i < argc; i++)
		a[i - 1] = atoi(argv[i]);
	if (has_duplicates(a, argc - 1) == 1 || !is_digits(a, argc - 1, argv))
	{
		printf("Error\n");
		return (0);
	}
	a[argc - 1] = 15;
	b[0] = 15;
	push_swap(a, b, argc - 1);
	return (0);
}