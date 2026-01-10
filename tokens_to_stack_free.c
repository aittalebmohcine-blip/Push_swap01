/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_stack_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:32:40 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:32:42 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	stack_add_back(t_stack	*stack, t_node *new)
{
	t_node	*tmp;

	if (!stack->top)
		stack->top = new;
	else
	{
		tmp = stack->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	stack->size++;
}

t_node	*new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack	*tokens_to_stack_free(char **tokens)
{
	t_stack	*stack;
	int		i;
	t_node	*node;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		node = new_node(ft_atoi(tokens[i]));
		if (!node)
		{
			free_stack(&stack);
			free_tokens(tokens);
			return (NULL);
		}
		stack_add_back(stack, node);
		i++;
	}
	free_tokens(tokens);
	return (stack);
}
