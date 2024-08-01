#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*src;
	int		i;
	int		src_len;

	src = (char *) s;
	src_len = ft_strlen(src);
	dup = malloc(sizeof(char) * src_len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
