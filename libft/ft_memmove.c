/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 22:00:38 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/26 18:28:53 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;
	size_t i;

	d = (unsigned char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s && d < s + n)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
	/*
	what i have learned ,

	so we te only thing that we need to check if if they are overlpaing or not if they
	ara overlpaped or not , that is main idea ,
		okay so we can do the other stuff

	lilke if they are overlpadfed please move some buffer step to next  bucket
	if they are not overlpaned call ft_memecpy!!


	*/