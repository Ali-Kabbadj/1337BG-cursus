/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:22:52 by akabbadj          #+#    #+#             */
/*   Updated: 2023/09/10 23:58:45 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./args_validation/args_validation.h"
# include "./args_validation/args_validation_macros.h"
# include "./error/error_handling.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
}					t_stack;

#endif
