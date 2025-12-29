#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stddef.h>
#include <stdlib.h>

//functions from tokenize.c file
int	ft_isspace(char c);
int	arg_is_valid(char *arg);
char *ft_strcat(char *dest, const char *src);
char	*group_args(size_t size, int ac, char **av);
char	**tokenizer(int ac, char **av);

//functions from valid_tokens.c file
int	valid_representation(char *token);
int	token_overflow(char *token);
int	validate_tokens(char **tokens);

//functions from transformer.c file
void free_tokens(char **tokens);
int	*tokens_to_int_and_free(char **tokens);

//functions from dup_checker.c file
int	has_duplicates(int *arr, int size);

//functions from push_swap.c file
void	error_exit(void);

#endif
