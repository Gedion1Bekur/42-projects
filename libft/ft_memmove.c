/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 22:00:38 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/25 22:08:40 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(size_t n, void dest[n], const void src[n], size_t n)
{
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr;
	const char *src_ptr;
	size_t start;

	start = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const char *)src;

	if (src_ptr < dest_ptr && dest_ptr < src_ptr + n)
	{
		while (n--)
		{
			
		}
		else
		{
			*dest_ptr++ = *src_ptr++;
			start++;+
	}
	return (dest_ptr);
}

// what are we doing  here :
/*
you will hav



*/