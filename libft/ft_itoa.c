#include "libft.h"

static void	write_s(char *s, int n, int i)
{
	int	neg;

	neg = 0;
	if (n < 0)
	{
		neg++;
		n = n * -1;
	}
	s[i] = '\0';
	i--;
	while (n / 10)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	s[i] = n + '0';
	if (neg)
	{
		i--;
		s[i] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		nb;
	int		i;

	nb = n;
	i = 1;
	if (nb < 0)
		i++;
	while (nb / 10)
	{
		nb = nb / 10;
		i++;
	}
	s = malloc(sizeof(char) * i + 1);
	if (s == NULL)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(s, "-2147483648", 11 + 1);
	else
		write_s(s, n, i);
	return (s);
}
