/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:31:43 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:31:44 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	chunks_algo(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	push_back_to_a(a, b);
}

void	sorting_algo(t_stack *a, t_stack *b)
{
	int	size;

	if (!indexing(a))
	{
		free_stack(&a);
		free_stack(&b);
		error_exit();
	}
	size = a->size;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		chunks_algo(a, b);
}
