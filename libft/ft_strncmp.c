#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	res = (unsigned char) s1[i] - (unsigned char) s2[i];
	if (res < 0)
		return (-1);
	else if (res > 0)
		return (1);
	else
		return (0);
}
