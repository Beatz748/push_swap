#include "push_swap.h"

t__int_b	do_r(t_base *base, t_steps current)
{
	while (current.rr--)
		b_rr(&base->stack_a, &base->stack_b, &base->cmds);
	while (current.rrr--)
		b_rrr(&base->stack_a, &base->stack_b, &base->cmds);
	while (current.rra--)
		b_rra(&base->stack_a, &base->cmds);
	while (current.rrb--)
		b_rrb(&base->stack_b, &base->cmds);
	while (current.ra--)
		b_ra(&base->stack_a, &base->cmds);
	while (current.rb--)
		b_rb(&base->stack_b, &base->cmds);
	return (SUCCESS);
}

t__int_b	perform_move(t_base *base)
{
	t_steps	current;

	current = calculate_steps(base);
	do_r(base, current);
	return (SUCCESS);
}

t__int_b	sorting(t_base *base)
{
	while (find_false_keep(base->stack_a))
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

t__int_b	sort(t_base *base, int count_nums)
{
	int	ret;

	ret = edit_keep_in(base);
	if (ret)
		return (ret);
	if (count_nums == 2 || count_nums == 3)
		return (sorting_two_three(base));
	else if (count_nums > 3)
		return (sorting(base));
	return (SUCCESS);
}
