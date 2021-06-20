#include "push_swap.h"

t__int_b	get_count_nums(t_stack *stack)
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
