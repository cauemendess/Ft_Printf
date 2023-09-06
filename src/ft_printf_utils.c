/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:14 by csilva-m          #+#    #+#             */
/*   Updated: 2023/09/06 10:22:07 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str == NULL)
	{
		return (ft_putstr("(null)"));
	}
	write(1, str, len);
	return (len);
}

int	ft_putnbr_base(long int nb, char *base)
{
	int	base_len;
	int	len;

	len = 0;
	base_len = ft_strlen(base);
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= base_len)
		len += ft_putnbr_base(nb / base_len, base);
	len += ft_putchar(base[nb % base_len]);
	return (len);
}

int	ft_putptr(unsigned long nb, char *base)
{
	unsigned long	base_len;
	int				len;

	len = 0;
	base_len = ft_strlen(base);
	if (nb == 0)
		return (ft_putstr("(nil)"));
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= base_len)
		len += ft_putptr(nb / base_len, base);
	else
		len += ft_putstr("0x");
	len += ft_putchar(base[nb % base_len]);
	return (len);
}
