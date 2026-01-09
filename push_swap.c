#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "libpushswap.h"

//////////////////////////////////////////
#include <stdio.h>
void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return;
	tmp = stack->top;
  if (!tmp)
    return;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
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

////////////////////////////
/*
	int	*arr;
	int	i = 0;
	arr = stack_to_arr(stack_a);
	while (i < stack_a->size)
		printf("%d\n", arr[i++]);
	bubble_sort(arr, stack_a->size);
	i = 0;
	while (i < stack_a->size)
		printf("--%d\n", arr[i++]);
	exit (0);
*/
/////////////////////////////

	//printf("-------------------\n");
  //print_stack(stack_a);
	//printf("-------------------\n");

	sorting_algo(stack_a, stack_b);

	//printf("-------------------\n");
  //print_stack(stack_a);
	//printf("-------------------\n");

	free_stack(&stack_a);
	free_stack(&stack_b);
	return 0;
}
