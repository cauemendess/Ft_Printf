/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:41:14 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/31 18:46:48 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	i;

	va_list args;           //lista de argumentos
	va_start(args, format); //inicia a lista
	int ret;                // vai receber o retorno da função
	i = -1;
	while (format[++i])
	{
		if (*format++ == '%')
			i = ft_validate(args, format[i + 1]);
		else
			ret += write(1, format[i], 1);
	}
	va_end(args);
	return (ret);
}

int	ft_validate(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
	{
		count += ft_putchar(va_arg(args, int));
	}
	else if (format == 's')
	{
		count += ft_putstr(va_arg(args, int));
	}
	else if (format == 'p')
	{
	}
	else if (format == 'i' || format == 'd')
	{
		count += ft_putnbr_base(va_arg(args, int), DEC_BASE);
	}
	else if (format == 'u')
	{
		count += ft_putnbr_base(va_arg(args, unsigned int), DEC_BASE);
	}
	else if (format == 'x')
	{
		count += ft_putnbr_base(va_arg(args, int), HEX_BASE);
	}
	else if (format == 'X')
	{
		count += ft_putnbr_base(va_arg(args, int), HEX_BASE_UPPER);
	}
	else if (format == '%')
	{
		count += ft_print_percent();
	}
	return (count);
}
