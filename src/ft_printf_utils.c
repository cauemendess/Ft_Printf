/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:07:14 by csilva-m          #+#    #+#             */
/*   Updated: 2023/09/04 17:58:33 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
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

int	ft_putnbr_base(long nb, char *base)
{
	
	int		base_len;
	int		len;

	len = 0;
	base_len = ft_strlen(base);

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	else if (nb >= base_len)
		len += ft_putnbr_base(nb / base_len, base);
	len += ft_putchar(base[nb % base_len]);
	return (len);
}

int ft_put_ptr(unsigned long nb, char *base)
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
		ft_putnbr_base(nbr / base_len, base);
	len += ft_putchar(base[nbr % base_len]);
	return (len);
}
