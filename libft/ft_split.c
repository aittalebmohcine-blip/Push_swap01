/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:14:39 by mait-tal          #+#    #+#             */
/*   Updated: 2025/11/03 16:14:46 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_all(char **res, int i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	word_start(const char *s, int n, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			if (w++ == n)
				return (i);
		}
		i++;
	}
	return (i);
}

static int	word_len(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i++] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		cnt;
	int		start;
	int		len;

	if (!s)
		return (NULL);
	cnt = count_words(s, c);
	res = malloc((cnt + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < cnt)
	{
		start = word_start(s, i, c);
		len = word_len(s, start, c);
		res[i] = malloc(len + 1);
		if (!res[i])
			return (free_all(res, i), NULL);
		ft_memcpy(res[i], s + start, len);
		res[i][len] = '\0';
	}
	res[i] = NULL;
	return (res);
}
