

#include "push_swap.h"

void push_swap(t_stack **stack_a, t_stack **stack_b, int stacksize)
{
    if (stacksize == 2 && !is_sorted(*stack_a))
        do_sa(stack_a);
    else if (stacksize == 3)
        small_sort(stack_a);
    else if (stacksize <= 5)
        medium_sort(stack_a, stack_b);
    else
        large_sort(stack_a, stack_b);
}

//tmp functions
void printstack(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        ft_printf("\nvalue :%d\nindex: %d\ntarget_pos: %d\npos :%d\n is_in_lis :%d\n",tmp->value, tmp->index, tmp->target_pos, tmp->pos, tmp->is_in_lis);
        if (tmp->next)
            ft_printf("next->value:%d\n\n", (tmp->next)->value);
        else
        {
            ft_printf("next->value : NULL");
        }
        tmp = tmp->next;
    }
    
}
//end tmp functions 


int main(int argc, char **argv)
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    int         stacksize;
    int         error_id;

    if (argc <= 2)
        exit_program(&stack_a, &stack_b, TOO_FEW_ARGS_ID);
    if ((error_id = is_valid_args(argc, argv)) != TRUE)
        exit_program(&stack_a, &stack_b, error_id);
    stack_b = NULL;
    stack_a = initialize_stack(argc, argv);
    stacksize = get_stack_size(stack_a);
    set_stack_indexes(stack_a);

    // ft_printf("\n\n------Before----\n\n");
    // printstack(stack_a);

    push_swap(&stack_a, &stack_b, stacksize);

    // ft_printf("\n\n------After----\n\n");
    // ft_printf("\n\n------Stack A----\n\n");
    // printstack(stack_a);
    // ft_printf("\n\n------Stack B----\n\n");
    // printstack(stack_b);
    
    return (0);
}