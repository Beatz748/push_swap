// #include "push_swap.h"

// static t__int_b	count_pairs(t_stack *stack, t_stack *start)
// {
// 	t_stack		*current;
// 	t__int_b	pairs;
// 	t__int_b	num;

// 	pairs = 1;
// 	num = start->order;
// 	current = start->down;
// 	while (current && current->order != start->order)
// 	{
// 		if (current->order > num)
// 		{
// 			num = current->order;
// 			++pairs;
// 		}
// 		else
// 		{
// 			num = B_INT64_MAX;
// 		}
// 		current = current->down;
// 		if (!current)
// 			current = stack;
// 	}
// 	return (pairs);
// }

// t__int_b	find_head_gt(t_stack *stack)
// {
// 	t_stack		*tmp;
// 	t__int_b	*pairs;
// 	t__int_b	i;
// 	t__int_b	max;

// 	pairs = (int *)malloc(get_count_nums(stack) * sizeof(int));
// 	i = 0;
// 	max = 0;
// 	tmp = stack;
// 	while (tmp)
// 	{
// 		pairs[i] = count_pairs(stack, tmp);
// 		if (pairs[max] <= pairs[i])
// 			max = i;
// 		++i;
// 		tmp = tmp->down;
// 	}
// 	while (max)
// 	{
// 		stack = stack->down;
// 		--max;
// 	}
// 	free(pairs);
// 	return (stack->order);
// }

// t__int_b	keep_in_gt(t_stack *stack)
// {
// 	t__int_b	head;
// 	t__int_b	ret;


// }
