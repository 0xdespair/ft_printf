#include "ft_printf.h"

static int	check_flag(char c);
static int	call_flag_func(va_list ap, const char c);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		char_counter;

	char_counter = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && check_flag(format[i + 1]))
		{
			char_counter += call_flag_func(ap, format[i + 1]);
			i = i + 2;
		}
		else
		{
			char_counter += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (char_counter);
}

static int	check_flag(char c)
{
	int		i;
	char	*supported_flag;

	supported_flag = ft_strdup("cspdiuxX%");
	i = 0;
	while (supported_flag[i])
	{
		if (c == supported_flag[i])
		{
			free(supported_flag);
			return (1);
		}
		i++;
	}
	free(supported_flag);
	return (0);
}

static int	call_flag_func(va_list ap, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, unsigned long)));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_putnbr(va_arg(ap, int), c));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
