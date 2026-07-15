/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:09:47 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/15 17:19:56 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	fnd;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	fnd = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == fnd)
		{
			return ((void *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
