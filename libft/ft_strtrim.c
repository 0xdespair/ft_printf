#include "libft.h"

static int	ft_start_trim(char const *s, char const *set)
{
	int	k;
	int	start_i;

	k = 0;
	start_i = 0;
	while ((size_t) k < ft_strlen((char *) set))
	{
		if (s[start_i] == set[k])
		{
			start_i++;
			k = 0;
		}
		else
			k++;
	}
	return (start_i);
}

static int	ft_end_trim(char const *s, char const *set)
{
	int	k;
	int	end_i;

	end_i = ft_strlen((char *) s) - 1;
	k = 0;
	while ((size_t) k < ft_strlen((char *) set))
	{
		if (s[end_i] == set[k])
		{
			end_i--;
			k = 0;
		}
		else
			k++;
	}
	return (end_i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	int		start_i;
	int		end_i;

	start_i = ft_start_trim(s1, set);
	if ((size_t) start_i == ft_strlen(s1))
	{
		s_trim = malloc(1);
		if (s_trim == NULL)
			return (NULL);
		s_trim[0] = '\0';
	}
	else
	{
		end_i = ft_end_trim(s1, set);
		s_trim = malloc(sizeof(char) * (end_i - start_i) + 1);
		if (s_trim == NULL)
			return (NULL);
		ft_strlcpy(s_trim, s1 + start_i, end_i - start_i + 1);
	}
	return (s_trim);
}
