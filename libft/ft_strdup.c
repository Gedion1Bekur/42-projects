/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:22:37 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/15 17:20:45 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*des;
	size_t	i;

	des = (char *)malloc(ft_strlen(s1) + 1);
	if (!des)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		des[i] = s1[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
