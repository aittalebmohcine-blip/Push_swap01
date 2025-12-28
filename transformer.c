#include "libft/libft.h"
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

int	*tokens_to_int_and_free(char **tokens)
{
	int	count;
	int	*result;
	int	i;

	count = 0;
	while(tokens[count])
		count++;
	result = malloc(sizeof(int) * count);
	i = 0;
	while (i < count)
	{
		result[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_tokens(tokens);
	return(result);
}
