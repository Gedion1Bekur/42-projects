/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:10:16 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/01 23:49:36 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long long n)
{
	char	*hex_base;
	int		printed;

	hex_base = "0123456789abcdef";
	printed = 0;
	if (n >= 16)
	{
		printed += ft_putptr_hex(n / 16);
	}
	write(1, &hex_base[n % 16], 1);
	printed++;
	return (printed);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					printed;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long long)ptr;
	write(1, "0x", 2);
	printed = 2;
	printed += ft_putptr_hex(addr);
	return (printed);
}
