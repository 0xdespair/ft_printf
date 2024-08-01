#include "ft_printf.h"

static int	print_hex(unsigned int nb, char *base, int len);

int	ft_puthex(int nb, char flag)
{
	unsigned int	u_nb;
	int				len;

	u_nb = nb;
	len = 0;
	if (flag == 'p')
	{
		len += ft_putstr("0x");
		len += print_hex(u_nb, "0123456789abcdef", 0);
		return (len);
	}
	else if (flag == 'x')
		return (print_hex(u_nb, "0123456789abcdef", 0));
	else if (flag == 'X')
		return (print_hex(u_nb, "0123456789ABCDEF", 0));
	return (0);
}

static int	print_hex(unsigned int nb, char *base, int len)
{
	if (nb / 16)
		len += print_hex(nb / 16, base, len);
	ft_putchar(base[nb % 16]);
	len++;
	return (len);
}
