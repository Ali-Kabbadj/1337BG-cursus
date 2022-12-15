/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:37:28 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/15 06:07:30 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
} t_stack;

// typedef struct s_stack
// {
//     int value;
//     int index;
//     int pos;
//     int target_pos;
//     int cost_a;
//     int cost_b;
//     struct s_stack *next;
// } t_stack;

void push_swap(int *a, int *b, int count);

/* Helpers */
void program_error(t_stack **stack_a, t_stack **stack_b);
long int ft_atoi(const char *str);

/* Stack Helpers*/
void free_stack(t_stack **stack);
t_stack *get_stack_tail(t_stack *stack);
t_stack *get_stack_tail_precedent(t_stack *stack);
t_stack *create_new_stack_node(int nb_value);
void set_new_stack_tail(t_stack **stack, t_stack *new);
int get_stack_size(t_stack *stack);

#endif