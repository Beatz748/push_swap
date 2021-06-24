#include "push_swap.h"

static t__int_b	adding_util_null(t_stack **stack, t__int64_b num)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
		return (ERROR_MALLOC);
	b_bzero(*stack, sizeof(t_stack));
	(*stack)->value = num;
	(*stack)->keep_in = FALSE;
	(*stack)->order = 0;
	return (SUCCESS);
	return (SUCCESS);
}

static t__int_b	add_last(t_stack **stack, int num, t_stack *begin, int order)
{
	(*stack)->down = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack)->down)
		return (ERROR_MALLOC);
	(*stack)->down->up = *stack;
	(*stack) = (*stack)->down;
	(*stack)->value = num;
	(*stack)->order = order;
	(*stack)->keep_in = FALSE;
	(*stack)->down = 0x000;
	*stack = begin;
	return (SUCCESS);
}

t__int_b	add_number_to_stack(t_stack **stack, t__int64_b num)
{
	t_stack		*tmp;
	t__int_b	order;

	tmp = *stack;
	order = 0;
	if (*stack == NULL)
		return (adding_util_null(stack, num));
	while ((*stack)->down)
	{
		if ((*stack)->value < num)
			++order;
		else
			(*stack)->order++;
		if ((*stack)->value == num || (*stack)->down->value == num)
			return (DUPLICATE_SYMBOLS);
		(*stack) = (*stack)->down;
	}
	if ((*stack)->value < num)
		++order;
	else
		(*stack)->order++;
	return (add_last(stack, num, tmp, order));
}

static t__int_b	argtoi_util(char *argv, t__int64_b *num, t__int_b *flag, int *j)
{
	*num = 0;
	*flag = 1;
	if (argv[*j] == '-')
	{
		*flag = 0;
		++*j;
	}
	return (SUCCESS);
}

t__int_b	argtoi(char **argv, t_base *base)
{
	t__int64_b	num;
	t__int_b	flag;
	t__int_b	i;
	t__int_b	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		argtoi_util(argv[i], &num, &flag, &j);
		while (argv[i][j] >= 0x030 && argv[i][j] <= 0x039)
		{
			if (num > B_INT64_MAX)
				return (INVALID_ARG);
			num = num * 10 + argv[i][j] - 0x030;
			++j;
		}
		if (argv[i][j])
			return (INVALID_ARG);
		if (flag == 0)
			num = ~(num - MINUS);
		add_number_to_stack(&base->stack_a, num);
		++i;
	}
	return (SUCCESS);
}
