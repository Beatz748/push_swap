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

t__int_b	gt_method(t_stack *a, t__int_b *num)
{
	if (a->order >= *num)
	{
		(*num) = a->order;
		a->keep_in = TRUE;
	}
	else
	{
		(*num) = B_INT_MAX;
		a->keep_in = FALSE;
	}
	return (SUCCESS);
}

t__int_b	keep_in_index(t_stack *stack, t__int_b head, t_base *base)
{
	t__int_b	index;
	t_stack		*a;
	t_bool		circle;

	a = stack;
	while (a->order != head)
		a = a->down;
	index = head;
	circle = FALSE;
	while (a)
	{
		if (a->order == head && circle)
			return (SUCCESS);
		base->method(a, &index);
		a = a->down;
		if (!a && !circle)
		{
			circle = TRUE;
			a = stack;
		}
	}
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

t__int_b	count_pairs_gt(t_stack *stack, t_stack *start)
{
	t_stack		*current;
	t__int_b	pairs;
	t__int_b	num;

	pairs = 1;
	num = start->order;
	current = start->down;
	while (current && current->order != start->order)
	{
		if (current->order > num)
		{
			num = current->order;
			++pairs;
		}
		else
			num = B_INT_MAX;
		current = current->down;
		if (!current)
			current = stack;
	}
	return (pairs);
}

t__int_b	find_head_index(t_stack *stack, t_base *base)
{
	t_stack		*tmp;
	t__int_b	*pairs;
	t__int_b	i;
	t__int_b	max;

	pairs = (int *)malloc(get_count_nums(stack) * sizeof(int));
	i = 0;
	max = 0;
	tmp = stack;
	while (tmp)
	{
		pairs[i] = base->pairs(stack, tmp);
		if (pairs[max] <= pairs[i])
			max = i;
		++i;
		tmp = tmp->down;
	}
	while (max)
	{
		stack = stack->down;
		--max;
	}
	free(pairs);
	return (stack->order);
}

t__int_b	edit_keep_in(t_base *base)
{
	t__int_b	head_num;
	t__int_b	ret;

	head_num = find_head_index(base->stack_a, base);
	ret = keep_in_index(base->stack_a, head_num, base);
	if (ret)
		return (ret);
	base->head = head_num;
	return (SUCCESS);
}
