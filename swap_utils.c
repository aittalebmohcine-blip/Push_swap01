#include "libpushswap.h"

void swap(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (!stack || !stack->top || !stack->top->next)
		return;
	tmp1 = stack->top;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	stack->top = tmp2;
}

void swap_a(t_stack *stack_a)
{
  swap(stack_a);
  write(1, "sa\n", 3);
}

void swap_b(t_stack *stack_b)
{
  swap(stack_b);
  write(1, "sb\n", 3);
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
  swap(stack_a);
  swap(stack_b);
  write(1, "ss\n", 3);
}
