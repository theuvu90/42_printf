/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thivu <thivu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:35:16 by thivu             #+#    #+#             */
/*   Updated: 2024/07/28 10:41:08 by thivu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	else if (n > 9)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
	return (ft_putchar(n + '0'));
}

int	ft_putnbr_unsig(unsigned int n)
{
	if (n > 9)
		return (ft_putnbr_unsig(n / 10) + ft_putnbr_unsig(n % 10));
	return (ft_putchar(n + '0'));
}
/*
ft_putnbr para numero tipo int, valor de -2147483648 a 2147483647
ft_putnbr_unsig para numero tipo unsigned int, valor de 0 a 4294967295
*/

int	ft_putnbr_hex(unsigned long nbr, char *base)
{
	if (nbr >= 16)
		return (ft_putnbr_hex(nbr / 16, base) + ft_putchar(base[nbr % 16]));
	return (ft_putchar(base[nbr]));
}
/*
base = "0123456789abcdef" si queremos imprimir en minuscula
base = "0123456789ABCDEF" si queremos imprimir en mayuscula
*/

int	ft_putpoint(unsigned long p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_putnbr_hex(p, "0123456789abcdef"));
}
