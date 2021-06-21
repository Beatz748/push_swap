#include "push_swap.h"

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->down)
		stack = stack->down;
	return (stack);
}

void	b_bzero(void *s, t__uint64_b n)
{
	t__uint64_b	i;

	i = 0;
	while (++i <= n && s)
	{
		*(char *)s = 0x000;
		++s;
	}
}

char	*b_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0x000;
	return (dest);
}

t__int_b	check_for_sorted(t_stack *stack)
{
	while (stack->down)
	{
		if (stack->value > stack->down->value)
			return (SUCCESS);
		stack = stack->down;
	}
	return (ALREADY_SORTED);
}
