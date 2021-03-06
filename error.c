#include "push_swap.h"

char	*b_stpncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = -1;
	while (++i < (int)len && src[i])
		dst[i] = src[i];
	while (dst[i])
	{
		dst[i] = 0;
		++i;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	write_error(int ret)
{
	char	buf[50];
	size_t	length;

	b_bzero((void *)buf, 50);
	b_stpncpy(buf, "ERROR\n PROBLEM --", 18);
	if (ret == FAIL)
		b_stpncpy(buf + 17, " SOMETHING WENT WRONG\n", 23);
	else if (ret == ERROR_MALLOC)
		b_stpncpy(buf + 17, " MALLOC IS BROKEN\n", 12);
	else if (ret == INVALID_ARG)
		b_stpncpy(buf + 17, " ONLY NUMERIC ARGS !!\n", 23);
	else if (ret == ENTER_ARGUMENT)
		b_stpncpy(buf + 17, " ARGUMENTS ARE BAD\n", 20);
	else if (ret == DUPLICATE_SYMBOLS)
		b_stpncpy(buf + 17, " DUPLICATE SYMBOLS\n", 20);
	else if (ret == NOT_ENOUGH_ELEMENTS)
		b_stpncpy(buf + 17, " NOT_ENOUGH_ELEMENTS\n", 22);
	else if (ret == ALREADY_SORTED)
		b_stpncpy(buf + 17, " ALREADY SORTED\n", 17);
	length = ft_strlen(buf);
	if (write(STDERR_FILENO, buf, length) != (int)length)
		return (FAIL);
	return (ret);
}
