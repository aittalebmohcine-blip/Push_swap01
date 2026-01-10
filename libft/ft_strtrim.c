/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:29:01 by mait-tal          #+#    #+#             */
/*   Updated: 2025/10/30 13:29:04 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	str_beg(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	set_len;

	set_len = ft_strlen(set);
	i = 0;
	while (s1[i])
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				count++;
			if (count == set_len)
				return (i);
			j++;
		}
		i++;
	}
	return (ft_strlen(s1));
}

static size_t	str_end(char const *s1, char const *set)
{
	size_t	j;
	size_t	count;
	size_t	set_len;
	size_t	s1_len;

	set_len = ft_strlen(set);
	s1_len = ft_strlen(s1);
	while (s1_len)
	{
		j = 0;
		count = 0;
		while (j < set_len)
		{
			if (s1[s1_len - 1] != set[j])
				count++;
			if (count == set_len)
				return (s1_len - 1);
			j++;
		}
		s1_len--;
	}
	return (ft_strlen(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_beg;
	size_t	s1_end;
	size_t	trim_len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	s1_beg = str_beg(s1, set);
	s1_end = str_end(s1, set);
	trim_len = s1_end - s1_beg + 1;
	result = malloc(trim_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1 + s1_beg, trim_len);
	result[trim_len] = '\0';
	return (result);
}
