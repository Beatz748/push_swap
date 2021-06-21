#include "push_swap.h"

static t__int_b	keep_in_util(t_stack *a, t__int_b *index)
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

t__int_b	keep_in_index(t_base *base, t__int_b head)
{
	t__int_b	index;
	t_stack		*a;
	t_bool		circle;

	a = base->stack_a;
	while (a->order != head)
		a = a->down;
	index = head;
	circle = FALSE;
	while (a)
	{
		if (a->order == head && circle)
			return (SUCCESS);
		keep_in_util(a, &index);
		a = a->down;
		if (!a && !circle)
		{
			circle = TRUE;
			a = base->stack_a;
		}
	}
	return (SUCCESS);
}

static t__int_b	count_pairs(t_stack *stack, t_stack *start)
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

static t__int_b	fin_head(t_stack *stack)
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
		pairs[i] = count_pairs(stack, tmp);
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
	t__int_b	head;
	t__int_b	ret;

	head = fin_head(base->stack_a);
	ret = keep_in_index(base, head);
	if (ret)
		return (ret);
	base->head = head;
	return (SUCCESS);
}
