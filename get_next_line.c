#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	gnl_util(char **tmp, char *buf, char **line)
{
	*tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(*tmp);
}

int	get_next_line(int fd, char **line)
{
	char	buf[2];
	int		sr;
	char	*tmp;

	sr = 0;
	buf[1] = '\0';
	if (!line)
		return (-1);
	*line = malloc(1);
	if (!(*line))
		return (-1);
	**line = 0;
	if (fd < 0 || !line)
		return (0);
	sr = read(fd, buf, 1);
	while (sr > 0)
	{
		if (*buf != '\n')
			gnl_util(&tmp, buf, line);
		else
			break ;
		sr = read(fd, buf, 1);
	}
	return (sr);
}
