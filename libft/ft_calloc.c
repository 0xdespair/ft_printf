#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*mem;

	if (nmenb == 0 || size == 0)
	{
		mem = malloc(0);
		if (mem == NULL)
			return (NULL);
	}
	else
	{
		mem = malloc(nmenb * size);
		if (mem == NULL)
			return (NULL);
		ft_bzero(mem, nmenb * size);
	}
	return (mem);
}
