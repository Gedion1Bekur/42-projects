/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:53:43 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/30 23:23:31 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			fnd;
	unsigned int	i;

	i = 0;
	fnd = (char)c;
	while (s[i] != '\0')
	{
		if ((s[i] == fnd))
			return ((char *)&s[i]);
		i++;
		if (s[i] == fnd)
			return ((char *)&s[i]);
	}
	return (NULL);
}
