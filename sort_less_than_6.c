/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:31:57 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:32:00 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	sort_2(t_stack *stack)
{
	t_node	*first;

	first = stack->top;
	if (first->index > first->next->index)
		swap_a(stack);
}

void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third)
	{
		reverse_rotate_a(a);
		if (first < third)
			swap_a(a);
	}
	else if (first > second && first > third)
	{
		rotate_a(a);
		if (second > third)
			swap_a(a);
	}
	else if (first > second && first < third)
		swap_a(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;
	int	forth;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	forth = a->top->next->next->next->index;
	if (first < second && second < third && third < forth)
		return ;
	else if (second == b->size)
		swap_a(a);
	else if (third == b->size)
	{
		reverse_rotate_a(a);
		reverse_rotate_a(a);
	}
	else if (forth == b->size)
		reverse_rotate_a(a);
	push_a_to_b(a, b);
	sort_3(a);
	push_b_to_a(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;
	int	forth;
	int	fifth;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	forth = a->top->next->next->next->index;
	fifth = a->top->next->next->next->next->index;
	if (first < second && second < third && third < forth && forth < fifth)
		return ;
	if (second == 0 || third == 0)
		rotate_a(a);
	if (third == 0)
		rotate_a(a);
	if (forth == 0 || fifth == 0)
		reverse_rotate_a(a);
	if (forth == 0)
		reverse_rotate_a(a);
	push_a_to_b(a, b);
	sort_4(a, b);
	push_b_to_a(a, b);
}
