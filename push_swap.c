#include "push_swap.h"

t__int_b			iterator_stack(t_stack *stack, t__int_b order)
{
	t__int_b	iter;

	iter = 0;
	while (stack && stack->order != order)
	{
		++iter;
		stack = stack->down;
	}
	return (iter);
}

t__int_b			keep_in_index(t_base *base, t__int_b head)
{
	t__int_b	index;
	t_stack	*a;
	t_bool	circle;

	a = base->stack_a;
	while (a->order != head)
		a = a->down;
	index = head;
	circle = FALSE;
	while (a)
	{
		if (a->order == head && circle)
			return (SUCCESS);
		if (a->order == index)
		{
			++index;
			a->keep_in = TRUE;
		}
		else
			a->keep_in = FALSE;
		a = a->down;
		if (!a && !circle)
		{
			circle = TRUE;
			a = base->stack_a;
		}
	}
	return (SUCCESS);
}

t__int_b			count_pairs(t_stack *stack, t_stack *start)
{
	t_stack	*current;
	t__int_b	pairs;
	t__int_b	index;

	pairs = 1;
	index = start->order;
	current = start->down;
	while (current && current->order != start->order)
	{
		if (current->order == index + 1)
		{
			++index;
			++pairs;
		}
		current = current->down;
		if (!current)
			current = stack;
	}
	return (pairs);
}

t__int_b			fin_head(t_stack *stack)
{
	t_stack	*tmp;
	t__int_b	*pairs;
	t__int_b	i;
	t__int_b	max;

	pairs = (int *)malloc(get_count_nums(stack) * sizeof(int));
	i = 0;
	max = 0;
	tmp = stack;
	while (tmp)
	{
		pairs[i] = count_pairs(stack, tmp);
		if (pairs[max] <= pairs[i])
			max = i;
		++i;
		tmp = tmp->down;
	}
	while (max)
	{
		stack = stack->down;
		--max;
	}
	free(pairs);
	return (stack->order);
}

t__int_b			edit_keep_in(t_base *base)
{
	t__int_b	head;
	t__int_b	ret;

	head = fin_head(base->stack_a);
	if ((ret = keep_in_index(base, head)))
		return (ret);
	base->head = head;
	return (SUCCESS);
}

void	print_commands(t_commands *cmds)
{
	while (cmds)
	{
		printf("%s\n", cmds->command);
		cmds = cmds->next;
	}
}

t__int_b			is_sorted(t_stack *stack)
{
	while (stack && stack->down)
	{
		if ((stack->value) > (stack->down->value))
			return (NOT_SORTED);
		stack = stack->down;
	}
	return (TRUE);
}

t__int_b			find_max_order_stack(t_stack *stack)
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

t__int_b			find_near_order(t_stack *stack, t__int_b target)
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
		ret = find_max_order_stack(safe);
	return (ret);
}

t__int_b			count_true_rule(t_stack *stack)
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

t_bool			prepare_sa(t_base *base)
{
	t__int_b	prev;
	t__int_b	new;

	prev = count_true_rule(base->stack_a);
	b_swap(base->stack_a);
	keep_in_index(base, base->head);
	new = count_true_rule(base->stack_a);
	b_swap(base->stack_a);
	keep_in_index(base, base->head);
	if (new > prev)
		return (TRUE);
	return (FALSE);
}

t__int_b			perform_sa(t_base *base)
{
	b_sa(&base->stack_a, &base->cmds);
	edit_keep_in(base);
	return (SUCCESS);
}

t_bool			find_false_keep(t_stack *stack)
{
	while (stack)
	{
		if (stack->keep_in == FALSE)
			return (TRUE);
		stack = stack->down;
	}
	return (FALSE);
}

t_steps			calculate_one(t_base *base, t__int_b current)
{
	t_steps	step;
	t__int_b	i;
	t__int_b	i_a;
	t__int_b	near_order_a;
	t__int_b	count_b;
	t__int_b	count_a;

	b_bzero(&step, sizeof(t_steps));
	near_order_a = find_near_order(base->stack_a, current);
	i_a = iterator_stack(base->stack_a, near_order_a);
	i = iterator_stack(base->stack_b, current);
	count_a = get_count_nums(base->stack_a);
	count_b = get_count_nums(base->stack_b);
	if (i < (count_b / 2) && (i_a < count_a / 2))
	{
		if (i > i_a)
		{
			step.rr = i_a;
			i -= i_a;
			i_a = 0;
		}
		else
		{
			step.rr = i;
			i_a -= i;
			i = 0;
		}
	}
	if (i > (count_b / 2) && (i_a > count_a / 2))
	{
		if (count_b - i < count_a - i_a)
		{
			step.rrr = count_b - i;
			i_a += step.rrr;
			i = count_b;
		}
		else
		{
			step.rrr = count_a - i_a;
			i += step.rrr;
			i_a = count_a;
		}
	}
	if (i < (count_b / 2))
	{
		step.rb = i;
		i = 0;
	}
	if (i_a < (count_a / 2))
	{
		step.ra = i_a;
		i_a = 0;
	}
	if (i >= (count_b / 2))
	{
		step.rrb = count_b - i;
		i = count_b;
	}
	if (i_a >= (count_a / 2))
	{
		step.rra = count_a - i_a;
		i_a = count_a;
	}
	step.res = step.ra + step.rb + step.rr + step.rrr + step.rra + step.rrb;
	step.order = current;
	return (step);
}

t_steps			calculate_steps(t_base *base)
{
	t_steps	steps[get_count_nums(base->stack_b)];
	t_steps	right;
	t_stack	*b;
	t_stack	*a;
	t__int_b	i;
	t__int_b	max;

	b = base->stack_b;
	i = 0;
	max = 0;
	while (b)
	{
		steps[i] = calculate_one(base, b->order);
		if (steps[max].res > steps[i].res)
			max = i;
		++i;
		b = b->down;
	}
	right = steps[max];
	return (right);
}

t__int_b			do_r(t_base *base, t_steps current)
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

t__int_b			perform_move(t_base *base)
{
	t_steps	current;

	current = calculate_steps(base);
	do_r(base, current);
	return (SUCCESS);
}

t__int_b			sorting(t_base *base)
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
		if (find_max_order_stack(base->stack_a) < get_count_nums(base->stack_a) / 2)
			b_ra(&base->stack_a, &base->cmds);
		else
			b_rra(&base->stack_a, &base->cmds);
	return (SUCCESS);
}



t__int_b			fast_sort(t_base *base, int count_nums)
{
	int	ret;

	if ((ret = edit_keep_in(base)))
		return (ret);
	if (count_nums == 2 || count_nums == 3)
		return (sorting_two_three(base));
	else if (count_nums > 3)
		return (sorting(base));
	return (SUCCESS);
}

int 			main(int argc, char **argv)
{
	int		ret;
	t_base	*base;

	if (!(base = (t_base *)malloc(sizeof(t_base))))
		return (write_error(ERROR_MALLOC));
	base->stack_a = NULL;
	base->stack_b = NULL;
	base->cmds = NULL;
	if (argc < MINIMUM_NUM_ARGS)
		return (write_error(ENTER_ARGUMENT));
	if (!!(ret = argtoi(++argv, base)))
		return (write_error(ret));
	if (!!(ret = check_for_sorted(base->stack_a)))
		return (write_error(ret));
	if (!!(ret = fast_sort(base, argc - 1)))
		return (write_error(ret));
	print_commands(base->cmds);
	return (SUCCESS);
}
