#include "libft.h"

static void	free_all(char **s_split)
{
	int	i;

	i = 0;
	while (s_split[i])
	{
		free(s_split[i]);
		i++;
	}
	free(s_split);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (j);
}

static char	*write_words(char const *s, int j, char c)
{
	char	*split;
	int		i;
	int		k;

	k = 0;
	while (s[j + k] != c && s[j + k])
		k++;
	split = malloc(sizeof(char) * k + 1);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < k)
	{
		split[i] = s[j + i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**s_split;
	int		i;
	int		j;

	s_split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (s_split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		s_split[i] = write_words(s, j, c);
		if (s_split[i] == NULL)
		{
			free_all(s_split);
			return (NULL);
		}
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	s_split[i] = NULL;
	return (s_split);
}
