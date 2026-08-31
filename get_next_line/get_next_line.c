/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:30:00 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/31 12:25:27 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_to_list(int fd, t_node **list)
{
	int	status;

	while (!find_newline(*list))
	{
		status = read_buffer(fd, list);
		if (status == 0)
			return (0);
		if (status == 2 || status == 3)
			return (1);
	}
	return (1);
}

t_node	*find_newline(t_node *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
				return (list);
			i++;
		}
		list = list->next;
	}
	return (NULL);
}

int	line_length(t_node *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			len++;
			if (list->str_buf[i++] == '\n')
				return (len);
		}
		list = list->next;
	}
	return (len);
}

char	*make_line(t_node *list)
{
	char	*line;
	int		i;
	int		j;
	int		len;

	len = line_length(list);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (list && i < len)
	{
		j = 0;
		while (list->str_buf[j] && i < len)
			line[i++] = list->str_buf[j++];
		list = list->next;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_node	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_to_list(fd, &list))
	{
		free_list(&list);
		return (NULL);
	}
	if (!list)
		return (NULL);
	line = make_line(list);
	if (!line)
	{
		free_list(&list);
		return (NULL);
	}
	clean_list(&list);
	return (line);
}
