#include "libpushswap.h"

int	find_index_position(t_stack *b, int index)
{
	t_node	*tmp;
	int		pos;

	tmp = b->top;
	pos = 1;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

int	find_max_index(t_stack *b)
{
	t_node	*tmp;
	int		max;

	tmp = b->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void	bring_pos_to_top_b(t_stack *b, int pos)
{
	int	moves;

	if (pos <= b->size / 2)
	{
		while (pos > 1)
		{
			rotate_b(b);
			pos--;
		}
	}
	else
	{
		moves = b->size - pos + 1;
		while (moves--)
			reverse_rotate_b(b);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max;
	int	pos;

	while (b->size > 0)
	{
		max = find_max_index(b);
		pos = find_index_position(b, max);
		bring_pos_to_top_b(b, pos);
		push_b_to_a(a, b);
	}
}
