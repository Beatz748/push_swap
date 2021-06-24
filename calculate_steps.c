#include "push_swap.h"

static t__int_b	iterator_stack(t_stack *stack, t__int_b order)
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

static t__int_b	init_calc_iter(t_base *base,
								t__int_b *curr,
									t__int_b *ia,
										t__int_b *ib)
{
	*ia = iterator_stack(base->stack_a, find_near_order(base->stack_a, *curr));
	*ib = iterator_stack(base->stack_b, *curr);
	return (SUCCESS);
}

static t__int_b	init_calc_count(t_base *base,
									t_steps *step,
										t__int_b *count_a,
											t__int_b *count_b)
{
	b_bzero(step, sizeof(t_steps));
	*count_a = get_count_nums(base->stack_a);
	*count_b = get_count_nums(base->stack_b);
	return (SUCCESS);
}

static t_steps	calculate_one(t_base *base, t__int_b current)
{
	t_steps		step;
	t__int_b	ib;
	t__int_b	ia;
	t__int_b	count_b;
	t__int_b	count_a;

	init_calc_iter(base, &current, &ia, &ib);
	init_calc_count(base, &step, &count_a, &count_b);
	if (ib <= (count_b / 2) && (ia <= count_a / 2))
		add_rr_step(&ib, &ia, &step);
	if (ib > (count_b / 2) && (ia > count_a / 2))
		add_rrr_step(&ib, &ia, &step, base);
	if (ib <= (count_b / 2))
		add_rx(&step.rb, &ib);
	if (ia <= (count_a / 2))
		add_rx(&step.ra, &ia);
	if (ib > (count_b / 2))
		add_rrx(&step.rrb, &count_b, &ib);
	if (ia > (count_a / 2))
		add_rrx(&step.rra, &count_a, &ia);
	step.res = step.ra + step.rb + step.rr + step.rrr + step.rra + step.rrb;
	step.order = current;
	return (step);
}

t_steps	calculate_steps(t_base *base)
{
	t_steps		steps
	[get_count_nums(base->stack_b)];
	t_steps		right;
	t_stack		*b;
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
