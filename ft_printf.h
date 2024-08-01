#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int nb);
int	ft_putstr(char *s);
int	ft_putnbr(int nb, char flag);
int	ft_puthex(int nb, char flag);
int	ft_putptr(unsigned long nb);

#endif