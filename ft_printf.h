/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thivu <thivu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:09:20 by thivu             #+#    #+#             */
/*   Updated: 2024/07/15 15:23:06 by thivu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsig(unsigned int n);
int	ft_putnbr_hex(unsigned long nbr, char *base);
int	ft_putpoint(unsigned long p);
int	ft_printf(char const *format, ...);

#endif
