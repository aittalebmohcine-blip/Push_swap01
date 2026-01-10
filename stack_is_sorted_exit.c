/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:32:12 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:32:14 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	stack_is_sorted_exit(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (!tmp)
		exit(1);
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			break ;
	}
	if (!tmp->next)
	{
		free_stack(&stack);
		exit(1);
	}
}
