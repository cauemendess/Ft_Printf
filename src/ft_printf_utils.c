/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:14 by csilva-m          #+#    #+#             */
/*   Updated: 2023/08/30 15:18:54 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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
		return (ft_putstr("(null)"));
	write(1, str, len);
	return (len);
}

int	ft_putnbr_base(int nb, char *base)
{
	long	nbr;
	int		base_len;
	int		len;

	len = 0;
	base_len = ft_strlen(base);
	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base);
	}
	if (nbr > base_len)
	{
		ft_putnbr_base(nbr / base_len, base);
	}
	len += ft_putchar(base[nbr % base_len]);
	return (len);
}

int	ft_putnbr_hex(int nb, char *base)
{
	long	nbr;
	int		base_len;
	int		len;

	len = 0;
	base_len = ft_strlen(base);
	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_hex(-nbr, base);
	}
	if (nbr > base_len)
	{
		ft_putnbr_hex(nbr / base_len, base);
	}
	else
		len += ft_putstr("0x");
	len += ft_putchar(base[nbr % base_len]);
	return (len);
}

int	main(void)
{
	ft_putnbr_base(645, "0123456789abcdef");
	printf("\n");
	ft_putnbr_hex(645, "0123456789abcdef");
}