/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tokens_orexit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:31:25 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:31:27 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
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
	return (tokens);
}
