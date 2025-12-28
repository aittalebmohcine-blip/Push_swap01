#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stddef.h>
#include <stdlib.h>

int	arg_is_valid(char *arg);
char *ft_strcat(char *dest, const char *src);
char	*group_args(size_t size, int ac, char **av);
char	**tokenizer(int ac, char **av);
int	validate_tokens(char **tokens);
int	*tokens_to_int_and_free(char **tokens);
int	has_duplicates(int *arr, int size);

#endif
