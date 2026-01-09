#include "libpushswap.h"


#include <stdio.h>
/*
///////////////////////////////////////////
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
		printf("%d\n", tmp->index);
		tmp = tmp->next;
	}
}
///////////////////////////////////////////
*/

void	chunks_algo(t_stack *a, t_stack *b)
{
	t_node	*head;
	int	min;
	int	max;
	int	range;
	int	curent_max_pos;

	min = 0;
	if (a->size <= 100)
		max = 21;
	else
		max = 40;
	// 55 : 708
	// 50 : 712
	// 60 : 718
	while (a->size)
	{
		head = a->top;
		if (b->size < max)
		{
			if (head->index < max && head->index >= min)
			{
				push_a_to_b(a, b);
				if (head->index < (max + min) / 2)
					rotate_b(b);
			}
			else
				rotate_a(a);
		}
		else
    {
			range  = max - min;
			min += range;
			max += range;
    }
	}
	while (b->size)
	{
		curent_max_pos = 1;
		head = b->top;
		while (head->index != b->size - 1)
		{
			head = head->next;
			curent_max_pos++;
		}
		if (curent_max_pos > b->size / 2)
		{
			while (b->size - curent_max_pos + 1)
			{
				reverse_rotate_b(b);
				curent_max_pos++;
			}
		}
		else
		{
			while (curent_max_pos - 1)
			{
				rotate_b(b);
				curent_max_pos--;
			}
		}
		push_b_to_a(a, b);
	}
}

void	sorting_algo(t_stack *a, t_stack *b)
{
	int	size;

	if (!indexing(a))
	{
		free_stack(&a);
		free_stack(&b);
		error_exit();
	}
	size = a->size;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		chunks_algo(a, b);
}
