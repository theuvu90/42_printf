/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thivu <thivu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:08:06 by thivu             #+#    #+#             */
/*   Updated: 2024/07/13 09:17:52 by thivu            ###   ########.fr       */
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
