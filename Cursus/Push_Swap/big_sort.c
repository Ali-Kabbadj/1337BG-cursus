/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:45:36 by akabbadj          #+#    #+#             */
/*   Updated: 2022/12/15 20:20:37 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push all from stack a to b exept three */
/*start by pushing smallest indexs as much as possible */
/*then push larger ones*/

void push_all_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    int stacksize;
    int i;
    int push_count;

    stacksize = get_stack_size(*stack_a);
    i = 0;
    push_count = 0;
    while (i < stacksize / 2 && stacksize > 6 && stacksize - push_count > 3)
    {
        /*to push smaller indexes first*/
        if ((*stack_a)->index < stacksize / 2)
        {
            do_pb(stack_a,stack_b);
            push_count++;
        }
        else
            do_ra(stack_a);
        i++;
    }
    
}
