#include "push_swap.h"

#include <stdio.h>
t__int_b			print_keep(t_stack *stack)
{
	while (stack)
	{
		printf("mark for %d is %d\n", stack->value, stack->keep_in);
		stack = stack->down;
	}
	return (SUCCESS);
}
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
	int	ret;

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

int	main(int argc, char **argv)
{
	int		ret;
	t_commands	*index;
	t_base	*base;

	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		return (write_error(ERROR_MALLOC));
	base->stack_a = NULL;
	base->stack_b = NULL;
	base->cmds = NULL;
	if (argc < MINIMUM_NUM_ARGS)
		return (write_error(ENTER_ARGUMENT));
	ret = argtoi(argv + 1, base);
	if (ret)
		return (write_error(ret));
	ret = check_for_sorted(base->stack_a);
	if (ret)
		return (write_error(ret));
	base->method = index_method;
	base->pairs = count_pairs_index;
	ret = sort(base, argc - 1);
	if (ret)
		return (write_error(ret));
	index = base->cmds;
	base->cmds = NULL;
	base->stack_a = NULL;
	base->stack_b = NULL;
	base->method = gt_method;
	base->pairs = count_pairs_gt;
	ret = argtoi(argv + 1, base);
	if (ret)
		return (write_error(ret));
	ret = sort(base, argc - 1);
	if (ret)
		return (write_error(ret));
	print_commands(base->cmds);
	return (SUCCESS);
}
