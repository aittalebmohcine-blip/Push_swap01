#include "libpushswap.h"
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>

//valid if: not impty || no cpaces only || more than leading + and/or - || other characaters but digits
int	arg_is_valid(char *arg)
{
	int	i;

	i = 0;
	while(arg[i] == ' ')
		i++;
	if (!arg[i])
		return(0);
	while((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '+' || arg[i] == '-' || arg[i] == ' ')
		i++;
	if (arg[i])
		return(0);
	return(ft_strlen(arg));
}

char *ft_strcat(char *dest, const char *src)
{
	int i;
	int j;
	
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*group_args(size_t size, int ac, char **av)
{
	int	i;
	char	*result;
	char	*space;

	space = " ";
	result = calloc(size + ac, sizeof(char));
	if (!result)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		ft_strcat(result, av[i]);
		ft_strcat(result, space);
		i++;
	}
	return (result);
}

char	**tokenizer(int ac, char **av)
{
	size_t	i;
	size_t	size;
	char	*args_grouped;
	char	**tokens;

	size = 0;
	//av[i] are valid , length of av[i]
	i = 1;
	while(i < ac)
	{
		if(!arg_is_valid(av[i]))
			return (NULL);
		size += arg_is_valid(av[i]);
		i++;
	}
	//for each av[i] strlcat(result, av[i])
	args_grouped = group_args(size, ac, av);
	tokens = ft_split(args_grouped, ' ');
	free(args_grouped);
	return(tokens);
}
