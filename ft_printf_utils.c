/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thivu <thivu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:08:06 by thivu             #+#    #+#             */
/*   Updated: 2024/08/15 11:42:15 by thivu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;	

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

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
