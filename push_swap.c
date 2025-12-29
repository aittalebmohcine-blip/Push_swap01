#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libpushswap.h"

void	error_exit(void)
{
	//write error to fd=2
	write(2, "Error\n", 6);
	exit(1);
}

// transformer all args into an arr of int. in case of error in the processe it exits with status 1
int	*processe_args(int ac, char **av)
{
	char	**tokens;
	int	count;
	int	*stack_a;

	tokens = tokenizer(ac, av);
	if (!tokens || !validate_tokens(tokens))
	{
		if (tokens)
			free_tokens(tokens);
    error_exit();
	}
	count = 0;
	while(tokens[count])
		count++;
	stack_a = tokens_to_int_and_free(tokens);
	if(has_duplicates(stack_a, count))//free befor exit in case of dups
	{
		free(stack_a);
		error_exit();
	}
	return(stack_a);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	// no params => display nothing
	if(ac == 1)
		return 0;
	stack_a = processe_args(ac, av);
	free(stack_a);
	return 0;
}
