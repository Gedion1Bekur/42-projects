/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:48:29 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/26 22:29:47 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	size_t				s_len;
	size_t				d_len;

	// first i gotta check if the dest have what enough space
	s_len = ft_strlen(s);
	d_len = ft_strlen(d);
	// here i need to know the actualll src length
	if (!size)
		return (s_len);
	if (d[i] && d_len == size)
		// gonnna know the last index of dest ,
		// so it will help me out to glue them
		while (s[i] && d[i] < size - 1)
		{
			d[i] = s[i];
			i++;
		}
	// while s goes to last index and dest + 1 next index can loop tell size
		-1 to save spat for terminotr
		// after truminted please return size
}
