#include "push_swap.h"

t_bool	prepare_sa(t_base *base)
{
	t__int_b	prev;
	t__int_b	new;

	prev = count_true_rule(base->stack_a);
	b_swap(base->stack_a);
	keep_in_index(base->stack_a, base->head, base);
	new = count_true_rule(base->stack_a);
	b_swap(base->stack_a);
	keep_in_index(base->stack_a, base->head, base);
	if (new > prev)
		return (TRUE);
	return (FALSE);
}

t__int_b	perform_sa(t_base *base)
{
	b_sa(&base->stack_a, &base->cmds);
	edit_keep_in(base);
	return (SUCCESS);
}
