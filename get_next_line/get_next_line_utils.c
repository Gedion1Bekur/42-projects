/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:44:38 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/31 12:25:31 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(t_node **list)
{
	t_node	*current;
	t_node	*next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current->str_buf);
		free(current);
		current = next;
	}
	*list = NULL;
}

int	add_node(t_node **list, char *buffer)
{
	t_node	*new_node;
	t_node	**link;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free(buffer);
		return (0);
	}
	new_node->str_buf = buffer;
	new_node->next = NULL;
	link = list;
	while (*link)
		link = &(*link)->next;
	*link = new_node;
	while (*buffer && *buffer != '\n')
		buffer++;
	if (*buffer == '\n')
		return (2);
	return (1);
}

int	read_buffer(int fd, t_node **list)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buffer);
		return (0);
	}
	if (bytes == 0)
	{
		free(buffer);
		return (3);
	}
	buffer[bytes] = '\0';
	return (add_node(list, buffer));
}

void	free_before(t_node **list, t_node *stop)
{
	t_node	*next;

	while (*list != stop)
	{
		next = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = next;
	}
}

void	clean_list(t_node **list)
{
	t_node	*current;
	int		i;
	int		j;

	current = find_newline(*list);
	if (!current)
	{
		free_list(list);
		return ;
	}
	i = 0;
	while (current->str_buf[i] != '\n')
		i++;
	i++;
	j = 0;
	while (current->str_buf[i])
		current->str_buf[j++] = current->str_buf[i++];
	current->str_buf[j] = '\0';
	free_before(list, current);
	if (!current->str_buf[0])
	{
		*list = current->next;
		free(current->str_buf);
		free(current);
	}
}
