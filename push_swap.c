#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libpushswap.h"


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
	stack_b = init_stack();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return 0;
}
