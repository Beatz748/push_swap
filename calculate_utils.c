#include "push_swap.h"

t__int_b	find_near_order(t_stack *stack, t__int_b target)
{
	t__int64_b	ret;
	t__int64_b	tmp;
	t_stack		*safe;

	ret = B_INT64_MAX;
	safe = stack;
	while (stack)
	{
		if (stack->order < ret && stack->order > target)
			ret = stack->order;
		stack = stack->down;
	}
	if (ret == B_INT64_MAX)
		ret = max_order_stack(safe);
	return (ret);
}

t__int_b	add_rr_step(t__int_b *ib, t__int_b *ia, t_steps *step)
{
	if (*ib < *ia)
	{
		step->rr = *ib;
		*ia -= *ib;
		*ib = 0;
	}
	else
	{
		step->rr = *ia;
		*ib -= *ia;
		*ia = 0;
	}
	return (SUCCESS);
}

t__int_b	add_rrr_step(int *ib, int *ia, t_steps *step, t_base *base)
{
	t__int_b	count_b;
	t__int_b	count_a;

	count_a = get_count_nums(base->stack_a);
	count_b = get_count_nums(base->stack_b);
	if (count_b - *ib < count_a - *ia)
	{
		step->rrr = count_b - *ib;
		*ia += step->rrr;
		*ib = count_b;
	}
	else
	{
		step->rrr = count_a - *ia;
		*ib += step->rrr;
		*ia = count_a;
	}
	return (SUCCESS);
}

t__int_b	add_rx(int *addr_rx, int *iter)
{
	*addr_rx = *iter;
	*iter = 0;
	return (SUCCESS);
}

t__int_b	add_rrx(t__int_b *addr, int *count, int *iter)
{
	*addr = *count - *iter;
	*iter = *count;
	return (SUCCESS);
}
