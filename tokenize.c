/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:35:14 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:35:17 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

// this file is all about making the args into tokens 
// in case of error in the args, the array of tokens is null
int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	arg_is_valid(char *arg)
{
	int	i;

	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (!arg[i])
		return (0);
	while (ft_isdigit(arg[i]) || arg[i] == '+' || arg[i] == '-'
		|| ft_isspace(arg[i]))
		i++;
	if (arg[i])
		return (0);
	return (i);
}

// a helper to concatenate args
char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

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

/*
the space to allocate is:
	the sum of len of each arg + one space for each arg
	the spaces added to separate each arg
*/
char	*group_args(size_t size, int ac, char **av)
{
	int		i;
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

// the main func of this file
// splits the grouped args and returns an array of tokens
// in case of an error it returns null
char	**tokenize(int ac, char **av)
{
	int		i;
	size_t	size;
	char	*args_grouped;
	char	**tokens;

	size = 0;
	i = 1;
	while (i < ac)
	{
		if (!arg_is_valid(av[i]))
			return (NULL);
		size += arg_is_valid(av[i]);
		i++;
	}
	args_grouped = group_args(size, ac, av);
	tokens = ft_spaces_split(args_grouped);
	free(args_grouped);
	return (tokens);
}
