/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:19:49 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:19:59 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void	free_all(char **res, int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static int	count_words(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	word_start(const char *s, int n)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]) && (i == 0 || ft_isspace(s[i - 1])))
		{
			if (w++ == n)
				return (i);
		}
		i++;
	}
	return (i);
}

static int	word_len(const char *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && !ft_isspace(s[i++]))
		len++;
	return (len);
}

char	**ft_spaces_split(char const *s)
{
	char	**res;
	int		i;
	int		cnt;
	int		start;
	int		len;

	if (!s)
		return (NULL);
	cnt = count_words(s);
	res = malloc((cnt + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < cnt)
	{
		start = word_start(s, i);
		len = word_len(s, start);
		res[i] = malloc(len + 1);
		if (!res[i])
			return (free_all(res, i), NULL);
		ft_memcpy(res[i], s + start, len);
		res[i][len] = '\0';
	}
	res[i] = NULL;
	return (res);
}
