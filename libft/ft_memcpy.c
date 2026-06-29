/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 21:39:14 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/29 23:08:01 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				start;

	if (!dest && !src)
		return (NULL);
	start = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	while (start < n)
	{
		*dest_ptr++ = *src_ptr++;
		start++;
	}
	return (dest);
}
