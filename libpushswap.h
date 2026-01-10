/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-tal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:22:34 by mait-tal          #+#    #+#             */
/*   Updated: 2026/01/10 11:22:36 by mait-tal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/* node structure */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* stack structure */
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* push_chunks_to_b.c */
void	push_chunks_to_b(t_stack *a, t_stack *b);

/* push_back_to_a.c */
void	push_back_to_a(t_stack *a, t_stack *b);

/* sort_less_than_6.c */
void	sort_2(t_stack *stack);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

/* indexing.c */
int		indexing(t_stack *a);

/* sorting_algo.c */
void	sorting_algo(t_stack *a, t_stack *b);

/* reverse_rotate.c */
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_a_b(t_stack *a, t_stack *b);

/* rotate.c */
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_a_b(t_stack *a, t_stack *b);

/* push.c */
void	push_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	push_b_to_a(t_stack *stack_a, t_stack *stack_b);

/* swap.c */
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);

/* stack_is_sorted_exit.c */
void	stack_is_sorted_exit(t_stack *stack);

/* tokens_to_stack_free.c */
t_stack	*tokens_to_stack_free(char **tokens);

/* set_tokens_orexit.c */
char	**set_tokens_orexit(int ac, char **av);
void	free_tokens(char **tokens);

/* utils.c */
void	error_exit(void);
t_stack	*init_stack(void);
void	free_stack(t_stack **stack);

/* tokenize.c */
char	**tokenize(int ac, char **av);
int		ft_isspace(char c);

/* validate_tokens.c */
int		validate_tokens(char **tokens);

/* stack_hasdup_exit.c */
void	stack_hasdup_exit(t_stack *stack);

/* ft_spaces_split.c */
char	**ft_spaces_split(char const *s);

#endif
