#include "push_swap.h"

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

t__int_b	head_util(t__int_b *i, t__int_b *max, t__int_b *head)
{
	*i = 0;
	*max = 0;
	*head = B_INT_MAX;
	return (SUCCESS);
}

t__int_b	head_util2(t_stack *stack, t__int_b max)
{
	while (max)
	{
		stack = stack->down;
		--max;
	}
	return (stack->order);
}

t__int_b	find_head_index(t_stack *stack, t_base *base)
{
	t_stack		*tmp;
	t__int_b	*pairs;
	t__int_b	i;
	t__int_b	max;
	t__int_b	head;

	pairs = (int *)malloc(get_count_nums(stack) * sizeof(int));
	head_util(&i, &max, &head);
	tmp = stack;
	while (tmp)
	{
		pairs[i] = base->pairs(stack, tmp);
		if (pairs[max] < pairs[i] || (pairs[max] == pairs[i]
				&& head > tmp->order))
		{
			head = tmp->order;
			max = i;
		}
		++i;
		tmp = tmp->down;
	}
	free(pairs);
	return (head_util2(stack, max));
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
