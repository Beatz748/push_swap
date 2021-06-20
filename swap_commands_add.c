#include "push_swap.h"

t__int_b	b_sa(t_stack **stack_a, t_commands **cmds)
{
	b_swap(*stack_a);
	add_command(cmds, "sa");
	return (SUCCESS);
}

t__int_b	b_sb(t_stack **stack_b, t_commands **cmds)
{
	b_swap(*stack_b);
	add_command(cmds, "sb");
	return (SUCCESS);
}
