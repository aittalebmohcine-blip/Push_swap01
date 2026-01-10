/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:08:14 by mait-tal          #+#    #+#             */
/*   Updated: 2025/10/31 13:08:21 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_cells(int n)
{
	int	cells;

	cells = 1;
	if (n < 0)
		cells++;
	while (n / 10)
	{
		cells++;
		n /= 10;
	}
	return (cells);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_cells(n);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (n < 0)
		n = -n;
	while (n)
	{
		result[size - 1] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	if (size)
		result[size - 1] = '-';
	return (result);
}
