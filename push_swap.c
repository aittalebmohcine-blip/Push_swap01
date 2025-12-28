#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libpushswap.h"

void	on_error()
{
	//write error to fd=2
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	char	**tokens;
	int	*stack_a;
	int	count;
	//arg != int || arg>int_max || duplicates => error
	//	error => display "Error\n" (error output : fd=2)

	// no params => display nothing
	if(ac == 1)
		return 0;
	// tokenizer is compleet, it returns an array of tokens
	// if one or more args not valid it returns null
	tokens = tokenizer(ac, av);
	if (!tokens || !validate_tokens(tokens))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	exit(0);
	count = 0;
	while(tokens[count])
		count++;
	stack_a = tokens_to_int_and_free(tokens);
	if(has_duplicates(stack_a, count))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	// next step is to check tokens if they are valid : num representation & no overflow & no dup
	return 0;
}
