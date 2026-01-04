#include "libpushswap.h"

// global funtions

void	error_exit(void)
{
	//write error to fd=2
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_node	*tmp;

	while ((*stack)->top)
	{
		tmp = (*stack)->top->next;
		free((*stack)->top);
		(*stack)->top = tmp;
	}
	free(*stack);
}
