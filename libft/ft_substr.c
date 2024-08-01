#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (len == 0 || start > ft_strlen(s))
		return (ft_strdup("\0"));
	else if (ft_strlen(s + start) < len)
		return (ft_strdup(s + start));
	sub_s = malloc(len + 1);
	if (sub_s == NULL || s == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			sub_s[i] = s[start + i];
			i++;
		}
	}
	sub_s[i] = '\0';
	return (sub_s);
}
