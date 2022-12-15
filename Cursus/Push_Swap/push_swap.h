#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h> 

//tmp includes 
#include <stdio.h>
//end tmp includes
typedef struct s_stack
{
    int value;
    int index;
    int pos;
    int target_pos;
    struct s_stack *next;
}   t_stack;

/* main */
void push_swap(t_stack **a, t_stack **b,int stacksize);

/* Helpers */
int ft_atoi(const char *s);
int char_is_digit(char c);

/* Error handling*/
void exit_error();

/* Initilizer*/
t_stack *initialize_stack(int argc, char **argv);
void set_stack_indexes(t_stack *stack_a);


/*Stack Helpers*/
t_stack *create_new_stack_node(int value);
t_stack *get_stack_tail(t_stack *stack);
t_stack *get_stack_tail_precedent(t_stack *stack);
void set_stack_new_tail(t_stack **stack, t_stack *newtail);
int get_stack_size(t_stack *stack);
int is_sorted(t_stack *stack);

/*Swap*/
void do_sa(t_stack **stack_a);
void do_sb(t_stack **stack_b);
void do_ss(t_stack **stack_a, t_stack **stack_b);

/*Push*/
void do_pa(t_stack **stack_a, t_stack **stack_b);
void do_pb(t_stack **stack_a, t_stack **stack_b);

/*Rotate*/
void do_ra(t_stack **stack_a);
void do_rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);

/*Reverse Rotate*/
void do_rra(t_stack **stack_a);
void do_rrb(t_stack **stack_b);
void do_rrr(t_stack **stack_a, t_stack **stack_b);


/*small sort*/
int get_max_index(t_stack *stack);
void small_sort(t_stack **stack_a);
#endif