/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:06:53 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/30 00:03:48 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_VALIDATION_H
# define ARGS_VALIDATION_H

# include "../../includes/error_handling/error_handling.h"
# include "../../libs/libft/libft.h"
# include "args_validation_utiles.h"

void	validate_args(int argc, char **argv);
void	validate_no_duplicates(int argc, char **argv);
void	validate_format(char *arg);

#endif