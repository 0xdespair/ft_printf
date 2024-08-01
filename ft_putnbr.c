#include "ft_printf.h"

static int	ft_putnbr_d(int nb);
static int	ft_putnbr_u(unsigned int nb);
static char	*ft_uitoa(unsigned int n);
static void	ft_uitoa_write(char *s, unsigned int n, int i);

int	ft_putnbr(int nb, char flag)
{
	int	len;

	len = 0;
	if (flag == 'd' || flag == 'i')
		len = ft_putnbr_d(nb);
	else
		len = ft_putnbr_u(nb);
	return (len);
}

static int	ft_putnbr_d(int nb)
{
	char	*s;
	int		len;

	s = ft_itoa(nb);
	len = ft_putstr(s);
	free(s);
	return (len);
}

static int	ft_putnbr_u(unsigned int nb)
{
	char	*s;
	int		len;

	s = ft_uitoa(nb);
	len = ft_putstr(s);
	free(s);
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*s;
	unsigned int	nb;
	int				i;

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
	else
		ft_uitoa_write(s, n, i);
	return (s);
}

static void	ft_uitoa_write(char *s, unsigned int n, int i)
{
	s[i] = '\0';
	i--;
	while (n / 10)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	s[i] = n + '0';
}
