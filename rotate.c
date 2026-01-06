#include "libpushswap.h"

int	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*old_top;

	if (!stack || !stack->top || !stack->top->next)
		return (0);
	old_top = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = old_top->next;
	old_top->next = NULL;
	last->next = old_top;
	return (1);
}

void	rotate_a(t_stack *a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack *a, t_stack *b)
{
	int	moved_a;
	int	moved_b;

	moved_a = rotate(a);
	moved_b = rotate(b);
	if (moved_a || moved_b)
		write(1, "rr\n", 3);
}
