#include "push_swap.h"

void	print_commands(t_commands *cmds)
{
	while (cmds)
	{
		if ((write (1, cmds->command, ft_strlen(cmds->command))
				!= ft_strlen(cmds->command)))
			exit(1);
		if ((write(1, "\n", 1) != 1))
			exit(1);
		cmds = cmds->next;
	}
}
