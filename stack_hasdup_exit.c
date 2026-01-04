#include "libpushswap.h"

int	check_dup(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = stack->top;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

void	stack_hasdup_exit(t_stack *stack)
{
	if (!stack || check_dup(stack))
	{
		if (stack)
			free_stack(&stack);
		error_exit();
	}
}
