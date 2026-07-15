/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:08:31 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/15 17:21:32 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_check(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*buf;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_set_check(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_set_check(s1[end - 1], set))
		end--;
	buf = ft_substr(s1, start, end - start);
	return (buf);
}
