#include "ft_printf.h"

int	ft_putchar(int nb)
{
	unsigned char	c;

	c = nb;
	write(1, &c, 1);
	return (1);
}
