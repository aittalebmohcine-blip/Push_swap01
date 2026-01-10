/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:31:02 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:31:04 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	before_last = stack->top;
	last = before_last->next;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = stack->top;
	stack->top = last;
	before_last->next = NULL;
	return (1);
}

void	reverse_rotate_a(t_stack *a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = reverse_rotate(a);
	moved_b = reverse_rotate(b);
	if (moved_a || moved_b)
		write(1, "rrr\n", 4);
}
