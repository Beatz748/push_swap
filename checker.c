// #include "push_swap.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned char	*str1;
// 	unsigned char	*str2;
// 	size_t			i;

// 	i = 0;
// 	if (!n)
// 		return (0);
// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	while (i < n && str1[i] == str2[i] && str1[i] && str2[i])
// 		i++;
// 	if (i == n)
// 		return (0);
// 	return (str1[i] - str2[i]);
// }

// t__int_b	perform_cmd(t_base *base, char *str)
// {
// 	if (str[4] != 0)
// 	{
// 		return (DUPLICATE_SYMBOLS);
// 	}
// 	if (!ft_strncmp("ra", str, 2))
// 		return (b_ra(&base->stack_a, &base->cmds));
// 	if (!ft_strncmp("rra", str, 3))
// 		return (b_rra(&base->stack_a, &base->cmds));
// 	if (!ft_strncmp("rb", str, 2))
// 		return (b_rb(&base->stack_b, &base->cmds));
// 	if (!ft_strncmp("rrb", str, 3))
// 		return (b_rrb(&base->stack_b, &base->cmds));
// 	if (!ft_strncmp("rr", str, 2))
// 		return (b_rr(&base->stack_a, &base->stack_b, &base->cmds));
// 	if (!ft_strncmp("rrr", str, 3))
// 		return (b_rrr(&base->stack_a,&base->stack_b, &base->cmds));
// 	if (!ft_strncmp("sa", str, 2))
// 		return (b_sa(&base->stack_a, &base->cmds));
// 	if (!ft_strncmp("sb", str, 2))
// 		return (b_sb(&base->stack_b, &base->cmds));
// 	// if (!ft_strncmp("ss", str, 2))
// 	// 	return (b_ss(&base->stack_a, &base->stack_b, &base->cmds));
// 	return (FAIL);
// }
// #include <stdio.h>
// t__int_b	checker(t_base *base, char **argv)
// {
// 	int	ret;
// 	char	*buf;

// 	ret = edit_keep_in(base);

// 	if (ret)
// 		return (ret);
// 	while (get_next_line(0, &buf))
// 	{
// 		ret = perform_cmd(base, buf);
// 		if (ret)
// 			return (ret);
// 		++(*argv);
// 		free(buf);
// 	}
// 	if (is_sorted(base->stack_a) == NOT_SORTED)
// 		write(1, "KO\n", 3);
// 	else
// 		write(1, "OK\n", 3);
// 	return (SUCCESS);
// }

// int	main(int argc, char **argv)
// {
// 	int		ret;
// 	t_base	*base;

// 	base = (t_base *)malloc(sizeof(t_base));
// 	if (!base)
// 		return (write_error(ERROR_MALLOC));
// 	base->stack_a = NULL;
// 	base->stack_b = NULL;
// 	base->cmds = NULL;
// 	if (argc < MINIMUM_NUM_ARGS)
// 		return (write_error(ENTER_ARGUMENT));
// 	ret = argtoi(++argv, base);
// 	if (ret)
// 		return (write_error(ret));
// 	ret = check_for_sorted(base->stack_a);
// 	if (ret)
// 		return (write_error(ret));
// 	ret = checker(base, argv);
// 	if (ret)
// 		return (write_error(ret));
// 	return (SUCCESS);
// }
