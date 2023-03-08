/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_macros.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:54:09 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/08 13:03:18 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MACROS
#define PUSH_SWAP_MACROS

#define FALSE 0
#define TRUE 1

#define ARG_INVALID_MSSG "One or more arguments are not valid\nthe arguments should be digits."
#define DUPLICATE_DIGIT_MSSG "You have entered one or more duplicate digits."
#define INT_MIN_MAX_MSSG "The integer arguments can't exceed the min and max int values [-2147483648,2147483647]"
#define TOO_FEW_ARGS_MSSG "You haven't entered enough arguments"

#define ARG_INVALID_ID -1
#define DUPLICATE_DIGIT_ID -2
#define INT_MIN_MAX_ID -3
#define TOO_FEW_ARGS_ID -4
#endif