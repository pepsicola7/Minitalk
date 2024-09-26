/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:25:36 by peli              #+#    #+#             */
/*   Updated: 2024/05/23 20:52:44 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_p(unsigned long long n)
{
	int	count;

	if (n == 0)
		return (ft_putstr("(nil)"));
	count = 0;
	count = ft_putstr("0x");
	count += ft_putnbr_hexa(n, "0123456789abcdef");
	return (count);
}

int	ft_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_put_p(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;
	unsigned int	i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (count);
}
