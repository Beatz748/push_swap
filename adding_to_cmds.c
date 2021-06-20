#include "push_swap.h"

t__int_b	add_command(t_commands **cmds, char *command)
{
	t_commands	*first;

	first = *cmds;
	if (*cmds == NULL)
	{
		*cmds = (t_commands *)malloc(sizeof(t_commands));
		if (*cmds == 0x000)
			return (ERROR_MALLOC);
		b_bzero(*cmds, sizeof(t_commands));
		(*cmds)->command = b_strdup(command);
		return (SUCCESS);
	}
	while ((*cmds)->next)
		(*cmds) = (*cmds)->next;
	(*cmds)->next = (t_commands *)malloc(sizeof(t_commands));
	if ((*cmds)->next == 0x000)
		return (ERROR_MALLOC);
	(*cmds)->next->command = b_strdup(command);
	(*cmds)->next->next = 0x000;
	(*cmds) = first;
	return (SUCCESS);
}
