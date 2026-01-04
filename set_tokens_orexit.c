#include "libpushswap.h"

void free_tokens(char **tokens)
{
    int i = 0;

    if (!tokens)
        return;
    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
}

char	**set_tokens_orexit(int ac, char **av)
{
	char	**tokens;

	tokens = tokenize(ac, av);
	if (!tokens || !validate_tokens(tokens))
	{
		if (tokens)
			free_tokens(tokens);
    error_exit();
	}
	//stack_a = tokens_to_int_and_free(tokens);
	/*if(has_duplicates(stack_a, count))//free befor exit in case of dups
	{
		free(stack_a);
		error_exit();
	}*/
	return(tokens);
}
