#include "push_swap.h"

__int_b			get_count_nums(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		++i;
		stack = stack->down;
	}
	return (i);
}

__int_b			        set_order(t_stack **stack)
{
	__int64_b	order;
	t_stack		*maximum;
	__int64_b	local_max;
	__int64_b	last_max;
	t_stack		*tmp;

	order = get_count_nums(*stack);
	local_max = B_INT64_MAX;
	last_max = B_INT64_MIN;
	maximum = NULL;
	tmp = *stack;
	while (order)
	{
		if (tmp->value > last_max && tmp->value < local_max)
		{
			maximum = tmp;
			last_max = tmp->value;
		}
		tmp = tmp->down;
		if (!tmp)
		{
			maximum->order = order--;
			local_max = maximum->value;
			tmp = *stack;
			last_max = B_INT64_MIN;
		}
	}
	return (SUCCESS);
}
