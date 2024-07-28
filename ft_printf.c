/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thivu <thivu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:06:36 by thivu             #+#    #+#             */
/*   Updated: 2024/07/15 15:28:48 by thivu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putpoint(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsig(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), HEX_LOWER));
	else if (format == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), HEX_UPPER));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_format(const char *format, va_list args, int *i)
{
	int	count;

	count = 0;
	if (*(format + *i) == '%' && *(format + *i + 1))
	{
		(*i)++;
		count = check_format(*(format + *i), args);
	}
	else if (*(format + *i) != '%')
		count = ft_putchar(*(format + *i));
	(*i)++;
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	if (format)
		while (*(format + i))
			count += ft_format(format, args, &i);
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int	main(){
	ft_printf("%c\n", 'm');
	printf("%c\n", 'm');
	// ft_printf("%s\n", "Hello World");
	// printf("%s\n", "Hello World");
	printf("n count for original: %d\n", printf("%s\n", "Hello World"));
	printf("n count for mine: %d\n", ft_printf("%s\n", "Hello World"));
	
	char *str = NULL;
	ft_printf("%s\n", str);
	printf("%s\n", str);
	printf("n count for original: %d\n", printf("%s\n", str));
	printf("n count for mine: %d\n", ft_printf("%s\n", str));
	
	int n = -2147483648;
	ft_printf("%d\n", n);
	printf("%d\n", n);
	ft_printf("%i\n", 0);
	printf("%i\n", 0);
	printf("n count for original: %d\n", printf("%d\n", n));
	printf("n count for mine: %d\n", ft_printf("%d\n", n));
	
	unsigned int num = 4294967295;
	ft_printf("%u\n", num);
	printf("%u\n", num);
	ft_printf("%u\n", 0);
	printf("%u\n", 0);
	printf("n count for original: %d\n", printf("%u\n", num));
	printf("n count for mine: %d\n", ft_printf("%u\n", num));
	
	unsigned int nbr = 442211;
	ft_printf("%x\n", nbr );
	printf("%x\n", nbr);
	ft_printf("%X\n", nbr);
	printf("%X\n", nbr);
	printf("n count for original: %d\n", printf("%x\n", nbr));
	printf("n count for mine: %d\n", ft_printf("%x\n", nbr));
	printf("n count for original: %d\n", printf("%X\n", nbr));
	printf("n count for mine: %d\n", ft_printf("%X\n", nbr));
	
	int nbr2 = 987654321;
	void * ptr = &nbr2;
	ft_printf("%p\n", ptr);
	printf("%p\n", ptr);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	printf("n count for original: %d\n", printf("%p\n", ptr));
	printf("n count for mine: %d\n", ft_printf("%p\n", ptr));
	
	ft_printf("100%%\n");
	printf("100%%\n");

	ft_printf("Hello %u %s 100%%\n", 42, "Madrid");
	printf("Hello %u %s 100%%\n", 42, "Madrid");	
	return (0);
}*/
