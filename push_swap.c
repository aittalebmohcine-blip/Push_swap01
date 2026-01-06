#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libpushswap.h"

///////////////////////////////////////////
#include <stdio.h>
void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return;
	printf("size : %d\n", stack->size);
	tmp = stack->top;
  if (!tmp)
    return;
	while (tmp->next)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->value);
}
///////////////////////////////////////////

int	main(int ac, char **av)
{
	char	**tokens;
	t_stack	*stack_a;
  t_stack *stack_b;

	if(ac == 1)
		return 0;
	tokens = set_tokens_orexit(ac, av);
	stack_a = tokens_to_stack_free(tokens);
	stack_hasdup_exit(stack_a);
	stack_is_sorted_exit(stack_a);
	stack_b = init_stack();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return 0;
}
