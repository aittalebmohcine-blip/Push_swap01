/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:11:03 by mait-tal          #+#    #+#             */
/*   Updated: 2025/11/03 16:11:29 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	signe_counter(const char *nptr)
{
	int	s_count;
	int	signe;
	int	i;

	s_count = 0;
	signe = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32
		|| nptr[i] == '+' || nptr[i] == '-')
	{
		if ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		else if (nptr[i] == '-' || nptr[i] == '+')
		{
			s_count++;
			if (nptr[i] == '-')
				signe *= -1;
			i++;
		}
	}
	return (s_count * signe);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	r;
	int	s_count;

	i = 0;
	r = 0;
	s_count = signe_counter(nptr);
	if (s_count >= -1 && s_count <= 1)
	{
		while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32
			|| nptr[i] == '+' || nptr[i] == '-')
			i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			r = r * 10 + (nptr[i] - '0');
			i++;
		}
		if (s_count == 0)
			return (r);
		else
			return (r * s_count);
	}
	return (0);
}
