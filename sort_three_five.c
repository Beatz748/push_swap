#include "push_swap.h"

t__int_b	is_there_order(t_stack *stack, t__int_b order)
{
	return (SUCCESS);
}

t__int_b	sort_five(t_base *base)
{
	t__int_b	order;

	order = get_count_nums(base->stack_a);
	// while (base->stack_a->order != order)
	return (SUCCESS);
}

t__int_b	sorting_two_three(t_base *base)
{
	t__int_b	ret;
	t_stack		*last;
	t_stack		**stack;

	stack = &base->stack_a;
	last = get_last(*stack);
	if ((*stack)->value > last->value)
		b_ra(&(base->stack_a), &(base->cmds));
	last = get_last(*stack);
	if ((*stack)->value > (*stack)->down->value)
		b_sa(&(base->stack_a), &(base->cmds));
	last = get_last(*stack);
	if ((*stack)->down->value > last->value)
	{
		b_sa(&(base->stack_a), &(base->cmds));
		b_ra(&(base->stack_a), &(base->cmds));
	}
	return (SUCCESS);
}
