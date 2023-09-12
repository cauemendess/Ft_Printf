/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsig_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:08:54 by csilva-m          #+#    #+#             */
/*   Updated: 2023/09/12 15:16:58 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putsig(long int nb, char *base, char specifier)
{
	int	len;

	len = 0;
	if ((specifier == '+') && nb >= 0)
		len += ft_putchar('+');
	if ((specifier == ' ') && nb >= 0)
		len += ft_putchar(' ');
	len += ft_putnbr_base(nb, base);
	return (len);
}
