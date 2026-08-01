/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:54:50 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/01 22:20:26 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *c)
{
	int	printed;

	printed = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
		printed++;
	}
	return (printed);
}
