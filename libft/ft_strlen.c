/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:27:08 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/15 17:21:09 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (s[ret] != '\0')
	{
		ret++;
	}
	return (ret);
}
