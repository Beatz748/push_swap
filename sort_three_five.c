#include "push_swap.h"

t__int_b	place_order(t_stack *stack, t__int_b order)
{
	t__int_b	place;

	place = 0;
	while (stack)
	{
		if (stack->order == order)
			return (place);
		stack = stack->down;
		++place;
	}
	return (place);
}

t__int_b	sort_five(t_base *base)
{
	while (is_sorted(base->stack_a) == NOT_SORTED)
		if (prepare_sa(base))
			perform_sa(base);
	else if (!(base->stack_a->keep_in))
		b_pb(&base->stack_a, &base->stack_b, &base->cmds);
	else
		b_ra(&base->stack_a, &base->cmds);
	while (base->stack_b)
	{
		perform_move(base);
		b_pa(&base->stack_a, &base->stack_b, &base->cmds);
	}
	while (is_sorted(base->stack_a) == NOT_SORTED)
		if (max_order_stack(base->stack_a) < get_count_nums(base->stack_a) / 2)
			b_ra(&base->stack_a, &base->cmds);
	else
		b_rra(&base->stack_a, &base->cmds);
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
