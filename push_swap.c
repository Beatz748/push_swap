#include "push_swap.h"

t__int_b	what_choose(t_commands	*gt, t_commands *index)
{
	t__int_b	gt_i;
	t__int_b	index_i;
	t_commands	*index_begin;
	t_commands	*gt_begin;

	index_begin = index;
	gt_begin = gt;
	index_i = 0;
	gt_i = 0;
	while (gt)
	{
		gt = gt->next;
		++gt_i;
	}
	while (index)
	{
		index = index->next;
		++index_i;
	}
	if (index_i > gt_i)
		print_commands(gt_begin);
	else
		print_commands(index_begin);
	return (SUCCESS);
}

t__int_b	confirm_index(t_base *base, int argc)
{
	t__int_b	ret;

	base->stack_b = NULL;
	base->cmds = NULL;
	base->method = index_method;
	base->pairs = count_pairs_index;
	ret = sort(base, argc - 1);
	return (ret);
}

t__int_b	confirm_gt(t_base *base, int argc, char **argv)
{
	t__int_b	ret;

	base->cmds = NULL;
	base->stack_a = NULL;
	base->stack_b = NULL;
	base->method = gt_method;
	base->pairs = count_pairs_gt;
	ret = argtoi(argv + 1, base);
	if (ret)
		return (write_error(ret));
	ret = sort(base, argc - 1);
	return (ret);
}

// int	main(int argc, char **argv)
// {
// 	int			ret;
// 	t_commands	*index;
// 	t_base		*base;

// 	base = (t_base *)malloc(sizeof(t_base));
// 	if (!base)
// 		return (write_error(ERROR_MALLOC));
// 	if (argc < MINIMUM_NUM_ARGS)
// 		return (write_error(ENTER_ARGUMENT));
// 	ret = argtoi(argv + 1, base);
// 	if (ret)
// 		return (write_error(ret));
// 	ret = check_for_sorted(base->stack_a);
// 	if (ret)
// 		return (write_error(ret));
// 	confirm_index(base, argc);
// 	if (ret)
// 		return (write_error(ret));
// 	index = base->cmds;
// 	ret = confirm_gt(base, argc, argv);
// 	if (ret)
// 		return (write_error(ret));
// 	what_choose(base->cmds, index);
// 	return (SUCCESS);
// }
