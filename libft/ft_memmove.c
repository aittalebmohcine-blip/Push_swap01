/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:22:30 by mait-tal          #+#    #+#             */
/*   Updated: 2025/11/02 23:22:35 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*start_d;
	const char	*start_s;
	size_t		i;

	start_d = (char *)dest;
	start_s = (const char *)src;
	i = 0;
	if (start_s == start_d || n == 0)
	{
		return (dest);
	}
	else if (start_d < start_s)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (i < n)
		{
			start_d[n - 1 - i] = start_s[n - 1 - i];
			i++;
		}
	}
	return (dest);
}
