#include "push_swap.h"

void			b_print_stack(t_stack *stack)
{
	t__int_b		i;

	i = -1;
	while (stack)
	{
		printf("order -- %d : value : %d (local order = %d)\n", ++i, stack->value, stack->order);
		stack = stack->down;
	}
}

t__int_b			check_for_sorted(t_stack *stack)
{
	while (stack->down)
	{
		if (stack->value > stack->down->value)
			return(SUCCESS);
		stack = stack->down;
	}
	return (ALREADY_SORTED);
}

t__int_b			add_number_to_stack(t_stack **stack, t__int64_b num)
{
	t_stack		*tmp;
	t__int_b	order;

	tmp = *stack;
	order = 0;
	if (*stack == NULL)
	{
		if (!(*stack = (t_stack *)malloc(sizeof(t_stack))))
			return (ERROR_MALLOC);
		b_bzero(*stack, sizeof(t_stack));
		(*stack)->value = num;
		(*stack)->keep_in = FALSE;
		(*stack)->order = order;
		return (SUCCESS);
	}
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
	if (!((*stack)->down = (t_stack *)malloc(sizeof(t_stack))))
			return (ERROR_MALLOC);
	(*stack)->down->up = *stack;
	(*stack) = (*stack)->down;
	(*stack)->value = num;
	(*stack)->order = order;
	(*stack)->keep_in = FALSE;
	(*stack)->down = 0x000;
	*stack = tmp;
	return (SUCCESS);
}

t__int_b			argtoi(char **argv, t_base *base)
{
	t__int64_b	num;
	t__int_b		flag;

	while (*argv)
	{
		num = 0;
		flag = 1;
		while (((flag) && **argv == '-' && ++(*argv) && !(flag = 0)) || (**argv >= 0x030 && **argv <= 0x039))
		{
			if (num > B_INT64_MAX)
				return (INVALID_ARG);
			num = num * 10 + **argv - 0x030;
			++(*argv);
		}
		if (**argv)
			return (INVALID_ARG);
		if (flag == 0)
			num = ~(num - MINUS);
		if ((flag = add_number_to_stack(&base->stack_a, num)))
			return (flag);
		++argv;
	}
	return (SUCCESS);
}
