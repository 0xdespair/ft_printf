#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;
	char	*temp_big;
	char	*temp_little;

	temp_big = (char *) big;
	temp_little = (char *) little;
	i = 0;
	if (temp_little[i] == '\0')
		return (temp_big);
	while (i < len && temp_big[i])
	{
		k = 0;
		if (temp_big[i] == temp_little[0])
		{
			while (temp_big[i + k] == temp_little[k] && i + k < len)
			{
				k++;
				if (k == ft_strlen(temp_little))
					return (&temp_big[i]);
			}
		}
		i++;
	}
	return (0);
}
