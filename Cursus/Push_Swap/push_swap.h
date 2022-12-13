/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:37:28 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/12 21:37:35 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
void    push_swap(int *a, int *b, int count);
int	has_duplicates(int *digits, int count);
int	is_digits(int *digits, int count, char *argv[]);
void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);
void	pb(int *a, int *b);
void	ra(int *a);
void	rb(int *b);
void    rr(int *a, int *b);
void	rra(int *a);
void	rrb(int *b);
void    rrr(int *a, int *b);
void sort_two_to_three(int *a, int *b);
#endif