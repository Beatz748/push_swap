#include "push_swap.h"

static t__int_b	argtoi_util(char *argv, t__int64_b *num, t__int_b *flag, int *j)
{
	*num = 0;
	*flag = 1;
	if (argv[*j] == '-')
	{
		*flag = 0;
		++*j;
	}
	return (SUCCESS);
}

static	t__int_b	argtoi_util2(int *flag, t_stack **stack_a,
									t__int64_b *num, char c)
{
	if (c)
		return (INVALID_ARG);
	if (*flag == 0)
		*num = ~((*num) - MINUS);
	*flag = add_number_to_stack(stack_a, *num);
	if (*flag)
		return (*flag);
	return (SUCCESS);
}

t__int_b	argtoi(char **argv, t_base *base)
{
	t__int64_b	num;
	t__int_b	flag;
	t__int_b	i;
	t__int_b	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		argtoi_util(argv[i], &num, &flag, &j);
		while (argv[i][j] >= 0x030 && argv[i][j] <= 0x039)
		{
			if (num > B_INT_MAX)
				return (INVALID_ARG);
			num = num * 10 + argv[i][j] - 0x030;
			++j;
		}
		argtoi_util2(&flag, &base->stack_a, &num, argv[i][j]);
		if (flag)
			return (flag);
		++i;
	}
	return (SUCCESS);
}
