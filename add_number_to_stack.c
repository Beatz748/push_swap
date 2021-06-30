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
