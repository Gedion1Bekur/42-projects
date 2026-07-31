/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:16:17 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/31 17:34:58 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:51:56 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/29 23:01:08 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int  format_delegetor(const char* c, void *args)
{
    if(c == 's')
        return ft_putstr(va_arg(c, char), args);
}

int	ft_printf(const char *format, ...)
{
	unsigned int i;
	va_list args;
	int counter;


	counter = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			counter += check_format(format[i], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			counter++;
		}
	}
	return (counter);
}