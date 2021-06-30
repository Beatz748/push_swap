#include "push_swap.h"

t__int_b	b_sa(t_stack **stack_a, t_commands **cmds)
{
	if ((*stack_a) && get_count_nums(*stack_a) > 1)
		b_swap(*stack_a);
	add_command(cmds, "sa");
	return (SUCCESS);
}

t__int_b	b_sb(t_stack **stack_b, t_commands **cmds)
{
	if ((*stack_b) && get_count_nums(*stack_b) > 1)
		b_swap(*stack_b);
	add_command(cmds, "sb");
	return (SUCCESS);
}

t__int_b	b_ss(t_stack **stack_a, t_stack **stack_b, t_commands **cmds)
{
	if ((*stack_a) && get_count_nums(*stack_a) > 1)
		b_sa(stack_a, cmds);
	if ((*stack_a) && get_count_nums(*stack_b) > 1)
		b_sa(stack_b, cmds);
	add_command(cmds, "ss");
	return (SUCCESS);
}
