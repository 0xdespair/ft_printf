#include "libft.h"

static int	adresscmp(void *dest, const void *src, int n)
{
	while (n > 0)
	{
		if (&src[n - 1] == dest)
			return (1);
		n--;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	i = 0;
	if (adresscmp(dest, src, n) == 0)
		ft_memcpy(temp_dest, temp_src, n);
	else
	{
		while (n > 0)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	}
	return (temp_dest);
}
