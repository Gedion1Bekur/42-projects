/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:35:51 by gbekur            #+#    #+#             */
/*   Updated: 2026/07/16 22:18:52 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
{
	void			*content;

	struct t_list	*next;

}					t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = lst;
	lst = new;
}
int	main(void)
{
	char *token = "hi how are you";

	t_list *node_1 = ft_lstnew(token);
	if (!node_1)
		return (1);
	printf("address of the node : %p\n ", (void *)node_1);
	printf("node content is here : %s\n", (char *)node_1->content);
	printf("node next %p\n", (void *)node_1->next);

	free(node_1);
	return (0);
}