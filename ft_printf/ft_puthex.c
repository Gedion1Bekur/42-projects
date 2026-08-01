/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:48:38 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/01 22:51:06 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int is_upper)
{
	char	*hex_base;
	int		printed;

	if (is_upper)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	printed = 0;
	if (n >= 16)
	{
		printed += ft_puthex(n / 16, is_upper);
	}
	write(1, &hex_base[n % 16], 1);
	printed++;
	return (printed);
}
