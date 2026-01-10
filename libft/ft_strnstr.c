/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:16:54 by mait-tal          #+#    #+#             */
/*   Updated: 2025/11/03 16:16:57 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && little[j] == big[i] && i < len)
		{
			j++;
			i++;
		}
		if (!little[j])
			return ((char *)big + i - j);
		if (big[i] != little[j])
			i = i - j;
		i++;
	}
	return (NULL);
}
