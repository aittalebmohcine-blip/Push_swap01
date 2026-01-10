/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:16:10 by mait-tal          #+#    #+#             */
/*   Updated: 2025/11/03 16:16:12 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	string = malloc(len_s1 + len_s2 + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < (len_s1 + len_s2))
	{
		if (i < len_s1)
			string[i] = s1[i];
		else
			string[i] = s2[i - len_s1];
		i++;
	}
	string[i] = '\0';
	return (string);
}
