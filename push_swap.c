/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:33:45 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:33:47 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	main(int ac, char **av)
{
	char	**tokens;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	tokens = set_tokens_orexit(ac, av);
	stack_a = tokens_to_stack_free(tokens);
	stack_hasdup_exit(stack_a);
	stack_is_sorted_exit(stack_a);
	stack_b = init_stack();
	sorting_algo(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
