/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linklist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:15:20 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/28 21:04:25 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct			node
{
	int			data;
	struct node	*link;
};
// there must be alwa

void	count_of_nodes(struct node *head)
{
	int			count;
	struct node	*ptr;

	count = 0;
	if (head == NULL)
	{
		printf("single linked list is empty");
		return ;
	}
	ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	printf("%d\n", count);
}
int	main(void)
{
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 50;
	head->link = NULL;

	count_of_nodes(head);
	struct node *currnet = malloc(sizeof(struct node));
	currnet->data = 51;
	currnet->link = NULL;
	head->link = currnet;

	currnet = malloc(sizeof(struct node));
	currnet->data = 52;
	currnet->link = NULL;

	head->link->link = currnet;

	currnet = malloc(sizeof(struct node));
	currnet->data = 53;
	currnet->link = NULL;
	head->link->link->link = currnet;
	count_of_nodes(head);
	// struct node *current = malloc(sizeof(struct node));

	// current->data = 51;
	// current->link = NULL;

	// head->link = current;

	// struct node *third = malloc(sizeof(struct node));

	// third->data = 52;
	// third->link = NULL;
	// struct node *forth = malloc(sizeof(struct node));

	// forth->data = 53;
	// forth->link = NULL;

	// third->link = forth;

	// current->link = third;
	printf("%d\n", head->data);
	printf("%p\n", head->link);

	printf("%d\n", head->link->link->data);
	printf("%p\n", head->link->link->link);

	printf("%d\n", currnet->data);
	printf("%p\n", currnet->link);
	// printf("%p\n", third->link);
	// printf("%d\n",forth->data);
	// printf("%p\n", forth->link);

	return (0);
}