/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:06:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/10 23:08:55 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_VALIDATION_H
# define ARGS_VALIDATION_H

# include "stdlib.h"

/*
	args_validation_utils.c
*/
void	valid_char(char arg, size_t *force_check_int, size_t *found_int_prev);
void	to_int_array(char **argv, int *integers);
size_t	count_nb_integers(int argc, char **argv);

/*
	args_validation.c
*/
void	validate_no_duplicates(int argc, char **argv);
void	validate_format(char *arg);
void	validate_args(int argc, char **argv);

#endif