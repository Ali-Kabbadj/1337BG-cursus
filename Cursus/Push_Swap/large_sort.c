/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbadj <akabbadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:45:36 by akabbadj          #+#    #+#             */
/*   Updated: 2023/03/11 06:40:15 by akabbadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push all from stack a to b exept three */
/*start by pushing smallest indexs as much as possible */
/*then push larger ones*/

// void push_all_to_stack_b(t_stack **stack_a, t_stack **stack_b)
// {
//     int stacksize;
//     int i;
//     int push_count;

//     stacksize = get_stack_size(*stack_a);
//     i = 0;
//     push_count = 0;
//     while (i < stacksize / 2 && stacksize > 6 && stacksize - push_count > 3 )
//     {
//         /*to push smaller indexes first*/
//         if ((*stack_a)->index < stacksize / 2)
//         {
//             do_pb(stack_a,stack_b);
//             stacksize--;
//             push_count++;
//         }
//         else
//             do_ra(stack_a);
//         i++;
//     }
//     while (stacksize - push_count > 3)
//     {
//         do_pb(stack_a, stack_b);
//         push_count++;
//     }
// }


void medium_sort_for_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    while (get_stack_size(*stack_a) > 3)
    {
        set_pos(stack_a);
        if ((*stack_a)->index ==  get_min_index(*stack_a) && (*stack_a)->index <= get_stack_size(*stack_a) / 2)
            do_pb(stack_a,stack_b);
        else
            get_closest_min_index_to_top(stack_a);
    }
}

void push_all_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    int stacksize;
    //int i;
    int push_count;

    // stacksize = 0;
    // i = 0;
    // push_count = 0;
    // while (i < stacksize / 2 && stacksize > 6 && stacksize - push_count > 3 )
    // {
    //     /*to push smaller indexes first*/
    //     if ((*stack_a)->index < stacksize / 2)
    //     {
    //         do_pb(stack_a,stack_b);
    //         stacksize--;
    //         push_count++;
    //     }
    //     else
    //         do_ra(stack_a);
    //     i++;
    // }
    // while (stacksize - push_count > 3)
    // {
    //     do_pb(stack_a, stack_b);
    //     push_count++;
    // }
    stacksize = get_stack_size(*stack_a);
    push_count = 0;
    // i = 0;
    // //ft_printf("%d", stacksize);
    // while (stacksize - get_stack_size(*stack_b) > 3)
    // {
    //     push_count = 0;
    //     while (push_count < 5)
    //     {
    //         //(*stack_a)->index <= get_stack_size(*stack_a) / 2
    //         stacksize = get_stack_size(*stack_a);
    //         if ((*stack_a)->index ==  get_min_index(*stack_a))
    //         {
    //             do_pb(stack_a,stack_b);
    //             push_count++;
    //         }
    //         else
    //         {
    //             get_closest_min_index_to_top(stack_a);
    //         }
    //     }
    //     //small_sort(stack_a);
    //     // while (get_stack_size(*stack_b) > 0)
    //     //     do_pa(stack_a,stack_b);
    //     //i++;
    // }
    while (push_count < 6)
    {
        do_pb(stack_a,stack_b);
        push_count++;
    }
    medium_sort_for_stack_b(stack_a, stack_b);
}

// typedef struct s_element_data
// {
//     int max_idx_in_range;
//     int min_idx_in_range;
//     int max_idx_pos;
//     int min_idx_pos;
// }   t_elemment_data;

// void set_values(t_stack *stack, t_elemment_data *element)
// {
//     static int range;
//     static int start;
//     static int end;
//     int current_pos;
//     t_stack *tmp;

//     range = 5;
//     end = start + range;
//     ft_memset(element, 0, sizeof(t_elemment_data));
//     current_pos = 0;
//     tmp = stack;
//     element->min_idx_in_range = INT_MAX;
//     element->min_idx_pos = INT_MAX;
//     while (end - current_pos > 0 && tmp->next)
//     {
//         if (tmp->index > element->max_idx_in_range)
//         {
//             element->max_idx_in_range = tmp->index;
//             element->max_idx_pos = tmp->pos;
//         }
//         if (tmp->index < element->min_idx_in_range)
//         {
//             element->min_idx_in_range = tmp->index;
//             element->min_idx_pos = tmp->pos;
//         }
//         current_pos++;
//         tmp = tmp->next;
//     }
//     start = current_pos + 1;
// }

// void sort_range(t_stack *stack, t_elemment_data *data)
// {
//     t_stack *tmp;
//     int nb_moves;

//     tmp = stack;
//     while (tmp->next)
//     {
//         set_values(stack, data);
//         nb_moves = 5 - data->min_idx_pos;
//         if ()
//         tmp = tmp->next;
//     }
    
// }

// void push_reverse_sorte_to_b(t_stack **stack_a, t_stack **stack_b)
// {
//     int push_count; //(0 --> 4) 
//     int pos;
//     t_elemment_data element;
//     int i;
//     int stack_size;
    
//     i = 0;
//     stack_size = get_stack_size(stack_a);
//     while (i < stack_size)
//     {
//         set_values(*stack_a, &element);
//         sort_range(*stack_a, &element);
//         i++;
//     }
    
// }

int get_target_pos(int b_index, int target_pos, t_stack **stack_a)
{
    t_stack *tmp_a;
    
    tmp_a = *stack_a;
    while (tmp_a->next)
    {
        if (tmp_a->index > b_index && target_pos <= INT_MAX)
        {
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    return (target_pos);
}

// void find_smallest_elememt(t_stack **stack)
// {
//     t_stack *tmp;
//     int min;
    
//     tmp = *stack;
//     min = INT_MAX;
//     while (tmp->next)
//     {
//         if ()
//         tmp = tmp->next;
//     }
    
// }

// min --> min int

// first value 5 ----> min 5
// second      10 ----> min 10
// ------      -3 ----> min 10
// -------     2 -----> min 10
// -------     7 -----> min 10
// ---------   22 -----> min 22

int get_correct_min_val(t_stack *stack)
{
    int min;
    t_stack *tmp;
    t_stack *tmp_2;
    int max_lis;
    int last_max_lis;
    
    tmp = stack;
    tmp_2 = tmp->next;
    min = tmp->value;
    
    max_lis = 0;
    last_max_lis = 0;
    while (tmp)
    {
        tmp_2 = tmp->next; 
        max_lis = 0;
        while (tmp_2)
        {
            if (tmp_2->value > tmp->value)
                max_lis++;       
            tmp_2 = tmp_2->next;
        }
        if (max_lis > last_max_lis)
        {
            last_max_lis = max_lis;
            min = tmp->value;
        }
        tmp = tmp->next;
    }
    return (min);
}

int set_lis(t_stack **stack)
{
    t_stack *tmp;
    int min;
    int lis_count;
    int last_value;

    tmp = *stack;
    lis_count = 1;
    min = get_correct_min_val(*stack);
    last_value = tmp->value;
    while (tmp)
    {
        if (tmp->value == min)
        {
            tmp->is_in_lis = 1;
            //ft_printf("%d\n", tmp->value );
            break;
        }
        tmp = tmp->next;
    }
    while (tmp)
    {
        if (tmp->value > min && tmp->value > last_value)
        {
            //ft_printf("%d\n", tmp->value);
            last_value = tmp->value;
            tmp->is_in_lis = 1;
            lis_count++;
        }
        tmp = tmp->next;
    }
    return (lis_count);
}

// void do_ra_ntimes()
// {
    
// }

void remove_element(t_stack **stack_a, t_stack **stack_b, int pos)
{
    int move_count;

    move_count = 0;
    if (pos <= get_stack_size(*stack_a) / 2)
    {
        while (move_count < pos)
        {
            do_ra(stack_a);
            move_count++;
        }
        do_pb(stack_a, stack_b);
    }
    else
    {
        while (move_count < pos)
        {
            do_rra(stack_a);
            move_count++;
        }
        do_pb(stack_a, stack_b);
    }
}

void remove_not_in_lis(t_stack **stack_a, t_stack **stack_b, int lis_count)
{
    t_stack *tmp;
    int i;
    int stacksize;
    
    tmp = *stack_a;
    i = 0;
    (void)lis_count;
    stacksize = get_stack_size(*stack_a);
    //ft_printf("%d",lis_count);
    while (tmp)
    {
        set_pos(stack_a);
        if (tmp->is_in_lis != 1)
        {
            ft_printf("%d\n",tmp->value);
            
            // remove_element(stack_a, stack_b , tmp->pos);
            // i++;
            stacksize = get_stack_size(*stack_b);
            //tmp = *stack_a;
        }
        tmp = tmp->next;
    }
    // if ((*stack_a)->index == get_max_index(*stack_a))
    //     do_ra(stack_a);
    // else if ((*stack_a)->index == get_max_index(*stack_a) - 1)
    //     do_sa(stack_a);
}






void large_sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    int lis_count;
    
    //push_all_to_stack_b(stack_a, stack_b);
    lis_count = 0;
    tmp_b = *stack_b;
    set_pos(stack_a);
    set_pos(stack_b);
    lis_count = set_lis(stack_a);
    printstack(*stack_a);
    remove_not_in_lis(stack_a, stack_b, lis_count);
    // ft_printf("%d", lis_count);
    // printstack(*stack_a);
    // while (tmp_b)
    // {
    //     tmp_b->target_pos = get_target_pos(tmp_b->index, INT_MAX, stack_a);
    //     tmp_b = tmp_b->next;
    // }
    
}

