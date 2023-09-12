/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:04:32 by csilva-m          #+#    #+#             */
/*   Updated: 2023/09/12 15:15:47 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define DEC_BASE "0123456789"

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base(long int nb, char *base);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putptr(unsigned long nb, char *base);
int		ft_puthex(long int nb, char *base, char specifier);
int		ft_putsig(long int nb, char *base, char specifier);

#endif
