/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utiles.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:38:07 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 12:02:09 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_VALIDATION_UTILES_H
# define ARGS_VALIDATION_UTILES_H

# include "../../includes/struct.h"
# include "stdlib.h"

int		ft_atoi_no_overflow(const char *str, int *integers);
void	valid_char(char arg, size_t *force_check_int, size_t *found_int_prev);
void	to_int_array(char **argv, int *integers);
size_t	count_nb_integers(int argc, char **argv);

#endif