#include "ft_printf.h"

static int	print_hex(unsigned long nb, char *base, int len);

int	ft_putptr(unsigned long nb)
{
	int	len;

	if (!nb)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	len += print_hex(nb, "0123456789abcdef", 0);
	return (len);
}

static int	print_hex(unsigned long nb, char *base, int len)
{
	if (nb / 16)
		len += print_hex(nb / 16, base, len);
	ft_putchar(base[nb % 16]);
	len++;
	return (len);
}
