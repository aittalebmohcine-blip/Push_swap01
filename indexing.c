#include "libpushswap.h"

int	*stack_to_arr(t_stack *stack)
{
	int	*arr;
	int	i;
	t_node	*tmp;

	arr = malloc(stack->size * sizeof(int));
	if (!arr)
		return (NULL);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	return (arr);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	indexing(t_stack *a)
{
	int	i;
	int	*arr;
	t_node	*tmp;

	if (!a || !a->top)
		return (0);
	arr = stack_to_arr(a);
	if (!arr)
		return (0);
	bubble_sort(arr, a->size);
	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < a->size && tmp->value != arr[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
	free(arr);
	return (1);
}
