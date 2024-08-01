#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	k;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	s = malloc(sizeof(char) * s_len + 1);
	if (s == NULL)
		return (NULL);
	while ((char) s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	k = 0;
	while ((char) s2[k])
	{
		s[i] = s2[k];
		i++;
		k++;
	}
	s[i] = '\0';
	return (s);
}
