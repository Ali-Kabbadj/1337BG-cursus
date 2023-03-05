

#include "push_swap.h"

void push_swap(t_stack **stack_a, t_stack **stack_b, int stacksize)
{
    if (stacksize == 2 && !is_sorted(*stack_a))
        do_sa(stack_a);
    else if (stacksize == 3)
        small_sort(stack_a);
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
        printf("\nvalue :%d\nindex: %d\ntarget_pos: %d\npos :%d\n",tmp->value, tmp->index, tmp->target_pos, tmp->pos);
        if (tmp->next)
            printf("next->value:%d\n\n", (tmp->next)->value);
        else
        {
            printf("next->value : NULL");
        }
        tmp = tmp->next;
    }
    
}
//end tmp functions 


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int stacksize;

    if (argc <= 2)
        return(0);
    if (!is_valid_args(argc, argv))
        exit_program(&stack_a, &stack_b);
    stack_b = NULL;
    stack_a = initialize_stack(argc, argv);
    stacksize = get_stack_size(stack_a);
    set_stack_indexes(stack_a);

    printstack(stack_a);
    push_swap(&stack_a, &stack_b, stacksize);
    printf("\nAfter----\n");
    printstack(stack_a);
    printf("\n\n|||||||||||\n\n");
    printstack(stack_b);
    
    return (0);
}