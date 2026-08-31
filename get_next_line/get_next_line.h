/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:00:00 by gbekur            #+#    #+#             */
/*   Updated: 2026/08/31 12:25:17 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*str_buf;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
int		read_to_list(int fd, t_node **list);
int		read_buffer(int fd, t_node **list);
t_node	*find_newline(t_node *list);
int		line_length(t_node *list);
char	*make_line(t_node *list);
void	clean_list(t_node **list);
void	free_list(t_node **list);
void	free_before(t_node **list, t_node *stop);
int		add_node(t_node **list, char *buffer);

#endif