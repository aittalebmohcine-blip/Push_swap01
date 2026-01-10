/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:29:58 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:30:00 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	in_current_chunk(int index, int min, int max)
{
	if (index >= min && index < max)
		return (1);
	return (0);
}

void	handle_push_or_rotate(t_stack *a, t_stack *b, int min, int chunk)
{
	int	index;

	index = a->top->index;
	push_a_to_b(a, b);
	if (index < min + (chunk / 2))
		rotate_b(b);
}

void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	chunk;

	if (a->size <= 100)
		chunk = 21;
	else
		chunk = 40;
	min = 0;
	max = chunk;
	while (a->size > 0)
	{
		if (in_current_chunk(a->top->index, min, max))
			handle_push_or_rotate(a, b, min, chunk);
		else
			rotate_a(a);
		if (b->size == max)
		{
			min += chunk;
			max += chunk;
		}
	}
}
