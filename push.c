#include "libpushswap.h"

int	push(t_stack *src, t_stack *dst)
{
	t_node	*tmp1;
	t_node	*tmp2;
	
	if (src->size == 0)
		return (0);
	tmp1 = dst->top;
	dst->top = src->top;
	tmp2 = src->top->next;
	src->top->next = tmp1;
	src->top = tmp2;
	src->size--;
	dst->size++;
	return (1);
}

void	push_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pb\n", 3);
}

void	push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
}
