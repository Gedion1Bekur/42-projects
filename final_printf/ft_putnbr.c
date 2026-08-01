/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:54:03 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/01 15:27:50 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursive_print(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
		printed += recursive_print(n / 10);
	printed += ft_putchar((n % 10) + '0');
	return (printed);
}

int	ft_putnbr(int n)
{
	unsigned int	unsigned_n;
	int				printed;

	printed = 0;
	if (n < 0)
	{
		printed += ft_putchar('-');
		unsigned_n = (unsigned int)(-(n + 1)) + 1;
	}
	else
		unsigned_n = (unsigned int)n;
	printed += recursive_print(unsigned_n);
	return (printed);
}
