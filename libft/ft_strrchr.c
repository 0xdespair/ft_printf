#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end_s;
	size_t	s_len;

	s_len = ft_strlen((char *) s);
	end_s = (char *) s + s_len - 1;
	if ((char) c == '\0')
		return ((char *) s + s_len);
	while (s_len > 0)
	{
		if (*end_s == (char) c)
			return (end_s);
		else
		{
			end_s--;
			s_len--;
		}
	}
	return (0);
}
