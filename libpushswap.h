#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
/////////////////////////////////////
#include <stdio.h>

//node structure
typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*next;
}	t_node;

//stack structure
typedef struct s_stack
{
	t_node	*top;
	int	size;
}	t_stack;

/////////////////////////
//sorting_algo.c
void	sorting_algo(t_stack *a, t_stack *b);
//int	*stack_to_arr(t_stack *stack);
//void	bubble_sort(int *arr, int size);

// reverse_rotate.c
// rra
void	reverse_rotate_a(t_stack *a);
// rrb
void	reverse_rotate_b(t_stack *b);
// rrr
void	reverse_rotate_a_b(t_stack *a, t_stack *b);

// rotate.c
// ra
void	rotate_a(t_stack *a);
// rb
void	rotate_b(t_stack *b);
// rr
void	rotate_a_b(t_stack *a, t_stack *b);

// push.c
// pb
void	push_a_to_b(t_stack *stack_a, t_stack *stack_b);
// pa
void	push_b_to_a(t_stack *stack_a, t_stack *stack_b);

// from swap.c
// sa
void swap_a(t_stack *stack_a);
// sb
void swap_b(t_stack *stack_b);
// ss
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);

// stack_is_sorted_exit.c
void	stack_is_sorted_exit(t_stack *stack);

// file : tokens_to_stack_free.c
t_stack	*tokens_to_stack_free(char **tokens);

// file : set_tokens_orexit.c
char	**set_tokens_orexit(int ac, char **av);
void	free_tokens(char **tokens);

//from utils.c
void	error_exit(void);
t_stack	*init_stack(void);
void	free_stack(t_stack **stack);

//functions from tokenize.c file
char	**tokenize(int ac, char **av);
int	ft_isspace(char c);

//functions from validate_tokens.c file
int	validate_tokens(char **tokens);

//functions from stack_hasdup_exit.c file
void	stack_hasdup_exit(t_stack *stack);

//from ft_spaces_split.c
char	**ft_spaces_split(char const *s);

#endif
