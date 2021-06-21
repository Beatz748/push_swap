#include "push_swap.h"

t__int_b	is_sorted(t_stack *stack)
{
	while (stack && stack->down)
	{
		if ((stack->value) > (stack->down->value))
			return (NOT_SORTED);
		stack = stack->down;
	}
	return (TRUE);
}

t_bool	find_false_keep(t_stack *stack)
{
	while (stack)
	{
		if (stack->keep_in == FALSE)
			return (TRUE);
		stack = stack->down;
	}
	return (FALSE);
}

t__int_b	count_true_rule(t_stack *stack)
{
	t__int_b	count;

	count = 0;
	while (stack)
	{
		if (stack->keep_in == TRUE)
			++count;
		stack = stack->down;
	}
	return (count);
}

t__int_b	max_order_stack(t_stack *stack)
{
	t__int_b	max;

	max = B_INT_MAX;
	while (stack)
	{
		if (max > stack->order)
			max = stack->order;
		stack = stack->down;
	}
	return (max);
}
