/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:48:11 by peli              #+#    #+#             */
/*   Updated: 2024/05/23 20:53:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int i)
{
	int	count;

	count = 0;
	if (i == -2147483648)
		return (ft_putstr("-2147483648"));
	if (i < 0)
	{
		count += write(1, "-", 1);
		i = -i;
	}
	if (i > 9)
		count += ft_putnbr(i / 10);
	count += ft_putchar(i % 10 + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int i)
{
	unsigned int	count;

	count = 0;
	if (i < 0)
	{
		write (1, "-", 1);
		i = -i;
	}
	if (i > 9)
		count += ft_putnbr_u(i / 10);
	count += ft_putchar(i % 10 + '0');
	return (count);
}

int	ft_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_hexa(unsigned long long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hexa(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}
