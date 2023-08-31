#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

#define HEX_BASE "0123456789abcdef"
#define HEX_BASE_UPPER "0123456789ABCDEF"
#define DEC_BASE "0123456789"

int	ft_printf(const char *format, ...);
int	ft_putnbr_base(int nb, char *base);
int	ft_putstr(char *str);

#endif
