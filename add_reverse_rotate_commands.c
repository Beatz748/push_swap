#include "push_swap.h"

t__int_b	b_rra(t_stack **stack_a, t_commands **cmds)
{
	b_reverse_rotate(stack_a);
	add_command(cmds, "rra");
	return (SUCCESS);
}

t__int_b	b_rrb(t_stack **stack_b, t_commands **cmds)
{
	b_reverse_rotate(stack_b);
	add_command(cmds, "rrb");
	return (SUCCESS);
}

t__int_b	b_rrr(t_stack **stack_a, t_stack **stack_b, t_commands **cmds)
{
	b_reverse_rotate(stack_a);
	b_reverse_rotate(stack_b);
	add_command(cmds, "rrr");
	return (SUCCESS);
}
