/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:07:37 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/01 22:01:42 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
		printed += ft_putunsigned(n / 10);
	printed += ft_putchar((n % 10) + '0');
	return (printed);
}
