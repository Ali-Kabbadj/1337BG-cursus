/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_macros.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:19:05 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/10 20:39:10 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_VALIDATION_MACROS_H
# define ARGS_VALIDATION_MACROS_H

# define TRUE 1
# define FALSE 0

# define ARG_INVALID_MSSG "One or more arguments are not valid. \
	Valid Format : [sign][digint(s)][space]...\n"

# define DUPLICATE_DIGIT_MSSG "You have entered one or \
    more duplicate integers.\n"

# define INT_MIN_MAX_MSSG "The integer arguments can't exceed \
    the MIN and MAX int values [-2147483648,2147483647]\n"

# define TOO_FEW_ARGS_MSSG "You haven't entered enough \
    arguments (MIN : 2 integers)\n"

# define MALLOC_ERROR_MSSG "Malloc failed to allocate memory.\n"

# define ARG_INVALID_ID -1
# define DUPLICATE_DIGIT_ID -2
# define INT_MIN_MAX_ID -3
# define TOO_FEW_ARGS_ID -4
# define MALLOC_ERROR_ID -5

#endif