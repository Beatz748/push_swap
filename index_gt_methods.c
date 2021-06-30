#include "push_swap.h"

t__int_b	index_method(t_stack *a, t__int_b *index)
{
	if (a->order == *index)
	{
		++(*index);
		a->keep_in = TRUE;
	}
	else
		a->keep_in = FALSE;
	return (SUCCESS);
}

t__int_b	count_pairs_index(t_stack *stack, t_stack *start)
{
	t_stack		*current;
	t__int_b	pairs;
	t__int_b	index;

	pairs = 1;
	index = start->order;
	current = start->down;
	while (current && current->order != start->order)
	{
		if (current->order == index + 1)
		{
			++index;
			++pairs;
		}
		current = current->down;
		if (!current)
			current = stack;
	}
	return (pairs);
}

t__int_b	gt_method(t_stack *a, t__int_b *num)
{
	if (a->order >= *num)
	{
		(*num) = a->order;
		a->keep_in = TRUE;
	}
	else
	{
		a->keep_in = FALSE;
	}
	return (SUCCESS);
}

t__int_b	count_pairs_gt(t_stack *stack, t_stack *start)
{
	t_stack		*current;
	t__int_b	pairs;
	t__int_b	num;

	pairs = 0;
	num = start->order;
	current = start->down;
	while (current && current->order != start->order)
	{
		if (current->order > num)
		{
			num = current->order;
			++pairs;
		}
		current = current->down;
		if (!current)
			current = stack;
	}
	return (pairs);
}
