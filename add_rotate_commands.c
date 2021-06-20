#include "push_swap.h"

t__int_b	b_ra(t_stack **stack_a, t_commands **cmds)
{
	b_rotate(stack_a);
	add_command(cmds, "ra");
	return (SUCCESS);
}

t__int_b	b_rb(t_stack **stack_b, t_commands **cmds)
{
	b_rotate(stack_b);
	add_command(cmds, "rb");
	return (SUCCESS);
}

t__int_b	b_rr(t_stack **stack_a, t_stack **stack_b, t_commands **cmds)
{
	b_rotate(stack_a);
	b_rotate(stack_b);
	add_command(cmds, "rr");
	return (SUCCESS);
}
