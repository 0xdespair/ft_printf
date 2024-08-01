#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_s;

	i = 0;
	temp_s = (unsigned char *) s;
	while (i < n)
	{
		if (*temp_s == (unsigned char) c)
			return (temp_s);
		else
		{
			temp_s++;
			i++;
		}
	}
	return (0);
}
