/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:53:48 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/15 17:21:27 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			fnd;
	char			*rember;

	i = 0;
	rember = NULL;
	fnd = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == fnd)
		{
			rember = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == fnd)
	{
		rember = (char *)&s[i];
	}
	return (rember);
}
