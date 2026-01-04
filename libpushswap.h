#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

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
